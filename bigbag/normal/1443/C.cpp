#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n;
pair<int, int> p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i].first);
        }
        long long tot = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i].second);
            tot += p[i].second;
        }
        sort(p, p + n);
        long long ans = p[n - 1].first, mx = 0;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, max(mx, tot));
            tot -= p[i].second;
            mx = max(mx, 1LL * p[i].first);
        }
        printf("%lld\n", ans);
    }
    return 0;
}