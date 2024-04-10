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

int n, m;
vector<string> grid;
vector<vector<bool>> bfs(int u, int v, vector<pair<int, int>> dirs) {
    queue<pair<int, int>> qu;
    vector<vector<bool>> reachable(n, vector<bool>(m));
    for (qu.push({u, v}), reachable[u][v] = 1; len(qu); qu.pop()) {
        u = qu.front().xx, v = qu.front().yy;
        for (auto dir: dirs) {
            int nu = u + dir.xx;
            int nv = v + dir.yy;
            if (nu < 0 or nv < 0) continue;
            if (nu >= n or nv >= m) continue;
            if (grid[nu][nv] == '#') continue;
            if (reachable[nu][nv]) continue;
            reachable[nu][nv] = 1;
            qu.push({nu, nv});
        }
    }
    return reachable;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    grid.resize(n);
    for (auto& i: grid) cin >> i;
    auto src_reachable = bfs(0, 0, {{0, 1}, {1, 0}});
    auto dst_reachable = bfs(n - 1, m - 1, {{0, -1}, {-1, 0}});
    if (!src_reachable[n - 1][m - 1]) {
        cout << 0;
        return 0;
    }

    vector<int> cnt(n + m -1);
    rep(i, n) rep(f, m) {
        if (i == 0 and f == 0) continue;
        if (i == n - 1 and f == m - 1) continue;

        if (src_reachable[i][f] and dst_reachable[i][f])
            cnt[i + f] ++;
    }
    for (auto i: cnt) {
        if (i == 1) {
            cout << 1;
            return 0;
        }
    }
    cout << 2;
    return 0;
}