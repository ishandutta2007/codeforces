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
        vector<pair<int, int>> e(m);
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            --t1; --t2;
            adj[t1].push_back(t2);
            adj[t2].push_back(t1);
            e[i] = {t1, t2};
        }
        vector <int> c(n, -1);
        auto DFS = y_combinator([&](auto self, int node) -> void {
            bool pos = true;
            for(auto next : adj[node]) {
                if(c[next] == 1) pos = false;
            }
            c[node] = pos ? 1 : 0;
            for(auto next : adj[node]) {
                if(c[next] == -1) self(next);
            }
        });
        DFS(0);
        bool pos = true;
        vector<vector<int>> g(n);
        for(auto i : e) {
            int a = c[i.first];
            int b = c[i.second];
            if(a == -1 || b == -1) pos = false;
            if(a == 1 && b == 1) pos = false;
            if((a == 1 && b == 0) || (b == 1 && a == 0)) {
                g[i.first].push_back(i.second);
                g[i.second].push_back(i.first);
            }
        }
        vector <int> d(n, -1);
        auto DFS2 = y_combinator([&](auto self, int node) -> void {
            d[node] = 1;
            for(auto next : adj[node]) {
                if(d[next] == -1) self(next);
            }
        });
        DFS2(0);
        int cnt = 0;
        for(auto i : d) if(i == 1) cnt++;
        if(cnt != n) pos = false;
        if(!pos) cout << "NO\n";
        else {
            cout << "YES\n";
            vector <int> ans;
            for(int i = 0; i < n; i++) {
                if(c[i] == 1) ans.push_back(i + 1);
            }
            cout << (int)ans.size() << '\n';
            for(auto i : ans) cout << i << " ";
            cout << '\n';
        }
    }
    
    return 0;
}