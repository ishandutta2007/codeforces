#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, inf = 1000111222;

int n, I, a[max_n], b[max_n], pr[max_n], suf[max_n];
map<int, int> cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &I);
    I *= 8;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    int nn  = n;
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int i = 0; i < n; ++i) {
        b[i] = cnt[a[i]];
    }
    int k = 0;
    while (k < 25 && (k + 1) * nn <= I) {
        ++k;
    }
    int tot = min(n, 1 << k);
    int r = 0, ans = inf;
    for (int i = 0; i < n; ++i) {
        pr[i] = b[i];
        if (i) {
            pr[i] += pr[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = b[i] + suf[i + 1];
    }
    for (int i = 0; i < n; ++i) {
        int res = 0;
        if (i) {
            res += pr[i - 1];
        }
        if (i + tot <= n) {
            res += suf[i + tot];
        }
        ans = min(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}