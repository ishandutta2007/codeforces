/**
 *  created: 25/01/2021, 17:07:17
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, a[max_n], b[max_n];
vector<int> all[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        all[1].clear();
        all[2].clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
            all[b[i]].push_back(a[i]);
        }
        sort(all[1].begin(), all[1].end());
        sort(all[2].rbegin(), all[2].rend());
        long long sum = accumulate(all[1].begin(), all[1].end(), 0LL);
        int ans = inf, pos = 0, res = all[1].size();
        for (int i = 0; i <= all[2].size(); ++i) {
            while (pos < all[1].size() && sum - all[1][pos] >= m) {
                sum -= all[1][pos];
                ++pos;
                --res;
            }
            //cout << i << ": " << sum << " " << res << endl;
            if (sum >= m) {
                ans = min(ans, res);
            }
            res += 2;
            if (i < all[2].size()) {
                sum += all[2][i];
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}