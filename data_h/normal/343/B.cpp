#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 111111;

char str[N];
int n;
int stack[N];
int main() {
    gets(str + 1);
    n = strlen(str + 1);
    int top = 0;
    for(int i = 1; i <= n; i++) {
        int x = 0;
        if (str[i] == '+')
            x = 1;
        if (top && stack[top] == x) {
            top--;
        } else {
            stack[++top] = x;
        }
    }
    if (top == 0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}