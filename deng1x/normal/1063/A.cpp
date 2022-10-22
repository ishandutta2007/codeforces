#include <bits/stdc++.h>

#define MAXN (100010)

int n;
char s[MAXN];
int cnt[26];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            putchar(i + 'a');
        }
    }
    puts("");
    return 0;
}