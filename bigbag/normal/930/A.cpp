#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int n, p[max_n], lev[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    ++cnt[0];
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &p[i]);
        lev[i] = lev[p[i]] + 1;
        ++cnt[lev[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += cnt[i] % 2;
    }
    printf("%d\n", ans);
    return 0;
}