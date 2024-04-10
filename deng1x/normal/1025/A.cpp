#include <bits/stdc++.h>

#define MAXN (100010)

int n;
char s[MAXN];
int cnt[26];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        ++ cnt[s[i] - 'a'];
    }
    if (n == 1) {
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > 1) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}