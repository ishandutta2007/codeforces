#include <bits/stdc++.h>

#define MAXN (200010)

int n;
char s[MAXN];

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        s[i + n] = s[i];
    }
    int ans = 1;
    int cnt = 1;
    for (int i = 1; i < n + n; ++i) {
        if (s[i] == s[i - 1]) cnt = 1;
        else ++ cnt;
        ans = std::max(ans, cnt);
    }
    printf("%d\n", std::min(ans, n));
    return 0;
}