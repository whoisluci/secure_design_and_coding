#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func1(){
    char buffer[8];
    int i = 0;
    char c;
    
    printf("Enter Input : ");
    
    while((c = getchar()) != '\n' && c != EOF && i < 7) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    
    printf("Input : %s\n", buffer);
}

void func2(){
    char buffer[8];
    char input[10];
    
    printf("Enter Input : ");
    fgets(input, sizeof(input), stdin);
    
    snprintf(buffer, sizeof(buffer), "User input: %s", input);
    
    printf("Input : %s\n", buffer);
}
void func3(){
    char buffer[8];
    char input[10];
    
    printf("Enter Input : ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input\n");
        return;
    } else {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
    }
    snprintf(buffer, sizeof(buffer), "%s", input);
    
    printf("Copied : %s\n", buffer);
}

int main(){
    func1();
    func2();
    func3();
    return 0;
}