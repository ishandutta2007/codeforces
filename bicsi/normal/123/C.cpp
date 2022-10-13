#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const long long kInf = 2e18;

long long Compute(vector<int> state) {
    int n = state.size();
    vector<long long> dp(n + 1), ndp(dp);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        fill(ndp.begin(), ndp.end(), 0);

        if (state[i] != -1) {
            for (int i = 0; i < n - 1; ++i) {
                ndp[i + 1] = min(kInf, ndp[i + 1] + dp[i]);
            }
        }
        if (state[i] != 1) {
            for (int i = 1; i < n; ++i) {
                ndp[i - 1] = min(kInf, ndp[i - 1] + dp[i]);
            }
        }
        swap(dp, ndp);
    }
    return dp[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; long long k; cin >> n >> m >> k;
    vector<pair<int, int>> smallest(n + m - 1);
    for (int i = 0; i < n + m - 1; ++i) { 
        smallest[i].second = i;
        smallest[i].first = 1e9;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            smallest[i + j].first = min(smallest[i + j].first, x);    
        }
    }
    

    sort(smallest.begin(), smallest.end());
    vector<int> state(n + m - 1, 0);
    for (auto p : smallest) { 
        int i = p.second;
        state[i] = +1;
        long long now = Compute(state);
        if (now < k) 
            k -= now, state[i] = -1;
    }  

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (state[i + j] == -1) cout << ")";
            if (state[i + j] == 1) cout << "(";
        }
        cout << endl;
    }  
    return 0;
}