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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> wt(n);
    vector <int> st(n); // sorted weights
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
        st[i] = wt[i];
    }
    sort(st.begin(), st.end());
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; --x; --y;
        adj[x].push_back(y);
    }
    int ans = (int)1E18;
    vector<vector<int>> g(n);
    vector<int> vis(n);
    bool cycle;
    auto CYCLE = y_combinator([&](auto self, int node) -> void {
        vis[node] = 1;
        for(auto next : g[node]) {
            if(vis[next] == 1) {
                cycle = true;
            }
            if(vis[next] == 0) {
                self(next);
            }
        }
        vis[node] = 2;
    });
    vector <int> top;
    auto TOP = y_combinator([&](auto self, int node) -> void {
        vis[node] = 1;
        for(auto next : g[node]) {
            if(vis[next] == 0) {
                self(next);
            }
        }
        top.push_back(node);
    });
    
    int l = 0;
    int r = n - 1;
    while(l <= r) {
        int m = (l + r)/2;

        bool check = false;
        // make a new graph.
        for(int i = 0; i < n; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            if(wt[i] > st[m]) continue;
            for(auto j : adj[i]) {
                if(wt[j] <= st[m]) {
                    g[i].push_back(j);
                }
            }
        }
        // if cycle exists in the graph -> true.
        cycle = false;
        for(int i = 0; i < n; i++) {
            if(wt[i] > st[m]) continue;
            if(vis[i] == 0) {
                CYCLE(i);
            }
        }
        // else if path of length k exists in the graph -> true
        if(cycle) check = true;
        else {
            // need topological order.
            for(int i = 0; i < n; i++) {
                vis[i] = 0;
            }
            top.clear();
            for(int i = 0; i < n; i++) {
                if(wt[i] > st[m]) continue;
                if(vis[i] == 0) {
                    TOP(i);
                }
            }
            // make DP in reverse topological order. 
            vector <int> dp(n, 1);
            for(auto node : top) {
                for(auto next : g[node]) {
                    dp[node] = max(dp[node], dp[next] + 1);
                }
            }
            for(int i = 0; i < n; i++) {
                if(dp[i] >= k) check = true;
            }
        }

        if(check) {
            ans = min(ans, st[m]);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ((ans == (int)1E18) ? -1 : ans) << '\n';
    
    return 0;
}