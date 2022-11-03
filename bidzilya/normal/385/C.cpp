#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

const int max_n = 1e7 + 10;

int d[max_n], dp[max_n];
vector<int> g;
ll ans[max_n];

int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    for (int i = 2; i < max_n; ++i) {
        if (d[i] == 0) {
            d[i] = i;
            dp[i] = i;
            g.push_back(i);
        }
        for (int j = 0; j < g.size() && g[j] <= d[i] && g[j] * i < max_n; ++j) {
            d[g[j] * i] = g[j];
            dp[g[j] * i] = g[j];
            if (g[j] == d[i])
                dp[g[j] * i] *= dp[i];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (x > 1) {
            ++ans[d[x]];
            x /= dp[x];
        }
    }
    for (int i = 1; i < max_n; ++i)
        ans[i] += ans[i - 1];
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l = min(l, max_n - 1);
        r = min(r, max_n - 1);
        cout << ans[r] - ans[l - 1] << endl;
    }
    return 0;
}