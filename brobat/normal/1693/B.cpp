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
            int x; cin >> x; --x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        int ans = 0;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        auto DFS = y_combinator([&](auto self, int node, int prev) -> int {
            if((int)adj[node].size() == 1 && node != prev) {
                ans++;
                return v[node].second;
            }
            int mx = 0;
            for(auto next : adj[node]) {
                if(next == prev) continue;
                mx += self(next, node);
            }
            if(mx < v[node].first) {
                ans++;
                mx = v[node].second;
            }
            return min(mx, v[node].second);
        });
        DFS(0, 0);
        cout << ans << '\n';
    }
    
    return 0;
}