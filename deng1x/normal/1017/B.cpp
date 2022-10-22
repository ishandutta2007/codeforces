#include <bits/stdc++.h>

#define MAXN (100010)

int n;
char s[MAXN], t[MAXN];
int cnt[2][2];

int main() {
    scanf("%d", &n);
    scanf("%s%s", s, t);
    for (int i = 0; i < n; ++i) {
        ++ cnt[s[i] - '0'][t[i] - '0'];
    }
    long long ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            int ii = ((j >> 1) & 1) * 2 + (i & 1);
            int jj = ((i >> 1) & 1) * 2 + (j & 1);
            if (((ii >> 1) | (ii & 1)) == ((i >> 1) | (i & 1)) && ((jj >> 1) | (jj & 1)) == ((j >> 1) | (j & 1))) continue;
            //printf("i = %d, j = %d\n", i, j);
            ans += 1ll * cnt[i >> 1][i & 1] * cnt[j >> 1][j & 1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}