#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to represent an account
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Array to hold the accounts
struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void createAccount();
void displayAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccount();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                checkBalance();
                break;
            case 6:
                printf("Thank you for using the Bank Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Bank is full. Cannot create more accounts.\n");
        return;
    }

    struct Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    printf("Enter the account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    printf("Enter the initial deposit amount: ");
    scanf("%f", &newAccount.balance);

    accounts[accountCount++] = newAccount;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void displayAccount() {
    int accountNumber;
    printf("Enter the account number to display: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        struct Account acc = accounts[accountNumber - 1];
        printf("\nAccount Number: %d\n", acc.accountNumber);
        printf("Account Holder: %s\n", acc.name);
        printf("Balance: $%.2f\n", acc.balance);
    } else {
        printf("Invalid account number.\n");
    }
}

void depositMoney() {
    int accountNumber;
    float amount;
    printf("Enter the account number to deposit: ");
    scanf("%d", &accountNumber);
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        accounts[accountNumber - 1].balance += amount;
        printf("Deposit successful. New balance: $%.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

void withdrawMoney() {
    int accountNumber;
    float amount;
    printf("Enter the account number to withdraw from: ");
    scanf("%d", &accountNumber);
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        if (accounts[accountNumber - 1].balance >= amount) {
            accounts[accountNumber - 1].balance -= amount;
            printf("Withdrawal successful. New balance: $%.2f\n", accounts[accountNumber - 1].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

void checkBalance() {
    int accountNumber;
    printf("Enter the account number to check balance: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        printf("Current balance: $%.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}
