#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    // int t;
    // cin >> t;
    // while(t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    p[0] = -1;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        --p[i];
        adj[p[i]].push_back(i);
    }
    vector <int> h(n), l(n), ans(n);
    function<void(int)> DFS = [&](int node) -> void {
        h[node] = 1;
        l[node] = 0;
        ans[node] = 0;
        // vector <int> t;
        for(auto nx : adj[node]) {
            DFS(nx);
            l[node] += l[nx];
            h[node] = max(h[node], h[nx] + 1);
            ans[node] += ans[nx];
        }
        if(l[node] = 0) l[node] = 1;
        ans[node] = max(ans[node], 1);
        ans[node] = max(ans[node], h[node]);
        ans[node] = max(ans[node], l[node]);
    };
    DFS(0);
    cout << ans[0];
    // }
    
    return 0;
}