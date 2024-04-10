#include <cstdio>
#include <cstring>

int n;
char s[2100];
int main() {
    scanf("%d%s", &n, s);
    int len = strlen(s), ans = 0;
    for(int i = n; i < len; i += n)
        if(s[i-1] == s[i-2] && s[i-2] == s[i-3]) ++ans;
    printf("%d\n", ans);
    return 0;
}