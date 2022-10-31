#include <bits/stdc++.h>
using namespace std;
char s[1000000 + 10];
int main() {
    scanf("%s", s);
    int l = strlen(s);
    for(int i = 0; i < l; ++i)
        if(s[i] == 'r')
            printf("%d\n", i + 1);

    for(int i = l - 1; i >= 0; --i)
        if(s[i] != 'r')
            printf("%d\n", i + 1);
    return 0;
}