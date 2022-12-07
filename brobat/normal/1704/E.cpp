#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

pair<bool, int> simulate(int n, vector<vector<int>> &temp, vector <int> &temp2, int dest) {
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        for(auto j : temp[i]) {
            adj[j].push_back(i);
        }
    }
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = temp2[i];
    }
    int add = 0;
    for(int i = 0; i <= 2*n; i++) {
        bool done = true;
        for(int j = 0; j < n; j++) {
            if(v[j] != 0) done = false;
        }
        if(done) {
            return {true, i};
        }
        if(v[dest] == 0) {
            add++;
        }
        vector <int> nv = v;
        for(int j = 0; j < n; j++) {
            if(v[j] > 0) {
                nv[j]--;
                for(auto nx : adj[j]) {
                    nv[nx]++;
                }
            }
        }
        v = nv;
    }
    return {false, add};
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> v(n);
        // vector <bool> exceed(n, false);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <vector <int>> adj(n);
        vector <int> prev(n, 0);
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[y].push_back(x);
            prev[x]++;
        }
        queue <int> q;
        vector <int> top;
        for(int i = 0; i < n; i++) {
            if(prev[i] == 0) {
                q.push(i);
            }
        }
        assert((int)q.size() == 1);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            top.push_back(curr);
            for(auto next : adj[curr]) {
                prev[next]--;
                if(prev[next] == 0) {
                    q.push(next);
                }
            }
        }
        assert((int)top.size() == n);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][j] --> no of paths of length j from i to destination.
        dp[top[0]][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                for(auto nx : adj[top[i]]) {
                    dp[nx][j + 1] += dp[top[i]][j];
                    // if(dp[nx][j + 1] > n) {
                    //     exceed[j + 1] = true;
                    // }
                    dp[nx][j + 1] %= MOD;
                }
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << top[i] + 1 << " : ";
        //     for(int j = 0; j < n; j++) {
        //         cout << dp[top[i]][j] << " ";
        //     }
        //     cout << '\n';
        // }
        vector <int> w(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                w[j] += dp[i][j] * v[i];
                // if(!exceed[j]) {
                //     if(w[j] > n) {
                //         exceed[j] = true;
                //     }
                // }
                w[j] %= MOD;
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << exceed[i] << " ";
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++) {
        //     cout << w[i] << " ";
        // }
        // cout << '\n';
        int ans = 0;

        // run a simulation for n seconds.

        auto p = simulate(n, adj, v, top[0]);
        // cout << p.first << " " << p.second << '\n';

        if(p.first) {
            cout << p.second << '\n';
            continue;
        }

        ans += p.second;

        for(int i = 0; i < n; i++) {
            // if(!exceeded) {
                // ans = max(ans, i);
            //     if(exceed[i]) exceeded = true;
            // }
            ans += w[i];
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    
    return 0;
}