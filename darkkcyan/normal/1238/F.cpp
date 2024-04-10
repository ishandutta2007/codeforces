#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

int n;
vector<vector<int>> gr;

tuple<vector<int>, vector<int>> topo_order(int root) {
    vector<int> ans(1, root);
    vector<int> parent(1, root);
    rep(i, len(ans)) {
        int u = ans[i];
        for (auto v: gr[u]) {
            if (v == parent[i]) continue;
            ans.push_back(v);
            parent.push_back(u);
        }
    }
    return {ans, parent};
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n;
        gr.assign(n + 1, vector<int>());
        rep(i, n - 1) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        int root = 1;
       
        assert(root != -1);
        auto [topo, parent] = topo_order(root);
        vector<pair<int, int>> ans(n + 1);
        for (int i = n; i--; ) {
            int u = topo[i], p = parent[i];

            int cost = len(gr[u]) - (p != u) + 1;
            ans[u] = {cost, cost};
            multiset<int> max_path;
            for (auto v: gr[u]) {
                if (v == p) continue;
                auto t = ans[v];
                ans[u].xx = max(ans[u].xx, t.xx);
                ans[u].yy = max(ans[u].yy, t.yy + cost - 1);
                max_path.insert(t.yy);
                if (len(max_path) > 2) max_path.erase(max_path.begin());
            }

            if (len(max_path) == 2) {
                ans[u].xx = max(ans[u].xx, *max_path.begin() + *max_path.rbegin() + cost - 2 + (p != u));
                // clog << *max_path.begin() << ' ' << *max_path.rbegin() << endl;
            }
            // clog << u << ' ' << ans[u].xx << ' ' << ans[u].yy << ' ' << cost << endl;
            ans[u].xx = max(ans[u].xx, ans[u].yy);
        }

        cout << ans[root].xx << '\n';
    }

    return 0;
}