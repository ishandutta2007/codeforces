/**
 *  created: 29/12/2021, 17:54:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 50555;
const long long inf = 1000111222000111222LL;

int t, n, x, a[max_n], mn[max_n], dp[max_n];
long long sum[max_n];

int func(int i) {
    return (i >= 2 ? dp[i - 2] : 0) - i + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cin >> x;
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + a[i] - x;
        }
        vector<pair<long long, int>> v;
        v.push_back({inf, -1});
        for (int i = 1; i <= n; ++i) {
            if (i != 1) {
                while (sum[i - 2] >= v.back().first) {
                    v.pop_back();
                }
                v.push_back({sum[i - 2], i - 2});
            }
            int id = lower_bound(v.rbegin(), v.rend(), make_pair(sum[i], max_n))->second;
            mn[i] = id + 2;
            //cout << "$" << i << " " << mn[i] << endl;
        }
        int pos = 1;
        multiset<int> vals, dps;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            vals.insert(mn[i]);
            dps.insert(func(i));
            while (*vals.rbegin() > pos) {
                vals.erase(vals.find(mn[pos]));
                dps.erase(dps.find(func(pos)));
                ++pos;
            }
            dp[i] = max(dp[i], *dps.rbegin() + i);
            //cout << i << " " << pos << ": " << dp[i] << "    " << *dps.rbegin() << endl;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}