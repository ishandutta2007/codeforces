#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    const int N = 1e6 + 4;
    vector<vector<int>> pos(N);
    vector<int> dp(N);

    for (int i = 0; i < N; ++i) {
        if (i < 10) {
            dp[i] = i;
        } else {
            int prod = 1;
            for (int aux = i; aux; aux /= 10) {
                if (aux % 10)
                    prod *= (aux % 10);    
            }
            assert(prod < i);
            dp[i] = dp[prod];
        }
        pos[dp[i]].push_back(i);
    }

    int q; cin >> q;
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        auto it2 = upper_bound(pos[k].begin(), pos[k].end(), r);
        auto it1 = lower_bound(pos[k].begin(), pos[k].end(), l);
        cout << it2 - it1 << '\n';
    }

    return 0;
}