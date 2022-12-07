#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n), g(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        f[x].push_back(y);
        g[y].push_back(x);
    }
    vector <int> top;
    {
        queue <int> q;
        // vector <bool> vis(n, false);
        vector <int> anc(n, 0);
        for(int i = 0; i < n; i++) {
            if((int)g[i].size() == 0) {
                q.push(i);
                // vis[i] = true;
            }
        }
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            top.push_back(x);
            for(auto nx : f[x]) {
                anc[nx]++;
                if(anc[nx] == (int)g[nx].size()) {
                    q.push(nx);
                }
            }
        }
    }
    // for(auto i : top) cout << i + 1 << " ";
    reverse(top.begin(), top.end());
    vector <int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        int x = top[i];
        // if((int)f[x].size() == 0) {
        //     dp[x] = 1;
        //     continue;
        // }
        // int y = 1;
        // for(auto nx : f[x]) {

        // }
        if((int)f[x].size() > 1) {
            int y = 1;
            for(auto nx : f[x]) {
                if((int)g[nx].size() > 1) {
                    y = max(y, dp[nx] + 1);
                }
            }
            dp[x] = y;
        }
    }
    cout << (*max_element(dp.begin(), dp.end()));
    
    return 0;
}