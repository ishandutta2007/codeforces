#include <stdio.h>
#define N 101
int main() {
    int i, c, st;
    char s[N];
    scanf("%s", s);
    st = 0, c = 1;
    for(i = 1; s[i] != '\0'; i++) {
        if(s[i] != s[i-1] || st + 5 <= i)
            st = i, c++;
    }
    printf("%d\n", c);
    return 0;
}