#include <bits/stdc++.h>
using namespace std;
#define int long long

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector <int> sz(n);
        vector <int> ans(n);
        auto DFS = y_combinator([&](auto self, int node, int prev) -> void {
            sz[node] = 1;
            int cnt = 0;
            vector <int> nx;
            for(auto next : adj[node]) {
                if(next == prev) continue;
                cnt++;
                self(next, node);
                nx.push_back(next);
                sz[node] += sz[next];
            }
            if(cnt == 0) {
                ans[node] = 0;
            } else if(cnt == 1) {
                ans[node] = sz[nx[0]] - 1;
            } else {
                int left = nx[0];
                int right = nx[1];
                ans[node] = max(sz[left] - 1 + ans[right], sz[right] - 1 + ans[left]);
            }
        });
        DFS(0, 0);
        cout << ans[0] << '\n';
    }
    
    
    return 0;
}