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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<pair<int, int>> edge;
        for(int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            --y; --z;
            if(x == 0) {
                edge.push_back({y, z});
            } else {
                adj[y].push_back(z);
            }
        }
        vector <int> vis(n, 0);
        bool cycle = false;
        auto CHECK_CYCLE = y_combinator([&](auto self, int node) -> void {
            vis[node] = 1;
            for(auto next : adj[node]) {
                if(vis[next] == 1) {
                    cycle = true;
                } else if(vis[next] == 0) {
                    self(next);
                }
            }
            vis[node] = 2;
        });
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                CHECK_CYCLE(i);
            }
        }
        if(cycle) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector <int> top;
        vector <int> p(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto j : adj[i]) {
                p[j]++;
            }
        }
        queue <int> q;
        for(int i = 0; i < n; i++) {
            vis[i] = -1;
            if(p[i] == 0) {
                vis[i] = 0;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            top.push_back(curr);
            for(auto next : adj[curr]) {
                p[next]--;
                if(p[next] == 0) {
                    q.push(next);
                }
            }
        }
        vector <int> ord(n);
        for(int i = 0; i < n; i++) {
            ord[top[i]] = i;
        }
        for(auto e : edge) {
            if(ord[e.first] < ord[e.second]) {
                adj[e.first].push_back(e.second);
            } else {
                adj[e.second].push_back(e.first);
            }
        }
        for(int i = 0; i < n; i++) {
            for(auto j : adj[i]) {
                cout << i + 1 << " " << j + 1 << '\n';
            }
        }
    }
    
    return 0;
}