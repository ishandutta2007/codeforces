/**
 *  created: 16/06/2022, 17:57:20
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, p[max_n], l[max_n], r[max_n];
int dp[max_n], val[max_n];
vector<int> g[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; ++i) {
            cin >> p[i];
            --p[i];
            g[p[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            long long sum = 0;
            dp[i] = 0;
            for (int to : g[i]) {
                dp[i] += dp[to];
                sum += val[to];
            }
            if (sum < l[i]) {
                ++dp[i];
                val[i] = r[i];
            } else {
                val[i] = min<long long>(sum, r[i]);
            }
        }
        cout << dp[0] << "\n";
        clr();
    }
    return 0;
}