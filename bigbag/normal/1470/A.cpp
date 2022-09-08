/**
 *  created: 05/01/2021, 16:39:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n, m, k[max_n], c[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &k[i]);
            --k[i];
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &c[i]);
        }
        long long cur = 0;
        sort(k, k + n);
        reverse(k, k + n);
        for (int i = 0; i < n; ++i) {
            cur += c[k[i]];
        }
        long long ans = cur;
        for (int i = 0; i < n && i < m; ++i) {
            cur += c[i] - c[k[i]];
            ans = min(ans, cur);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}