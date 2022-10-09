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

#define maxn 201010
int k, n;
vector<pair<int, int>> gr[maxn];

pair<llong, int> ans_min[maxn];
void cal_min(int u, int p) {
    ans_min[u] = {0, 1};
    for (auto [v, d]: gr[u]) {
        if (v == p) continue;
        cal_min(v, u);
        ans_min[u].xx += ans_min[v].xx;
        ans_min[u].xx += ans_min[v].yy * d;
        ans_min[u].yy += ans_min[v].yy;
    }
    ans_min[u].yy &= 1;
    // clog << u << ' ' << ans_min[u].xx << ' ' << ans_min[u].yy << endl;
}

int cnt_child[maxn];
void dfs_count_child(int u, int p) {
    cnt_child[u] = 1;
    for (auto [v, _]: gr[u]) {
        if (v == p) continue;
        dfs_count_child(v, u);
        cnt_child[u] += cnt_child[v];
    }
}

int find_centroid(int s) {
    int u = s, p = s, total = cnt_child[s];
    while (1) {
        pair<int, int> big(0, -1);
        if (p != u) big = {total - cnt_child[u], p};

        for (auto [v, _]: gr[u]) {
            if (v == p) continue;
            big = max(big, {cnt_child[v], v});
        }
        if (big.xx <= total / 2) return u;
        p = u;
        u = big.yy;
    }
    assert(false);
    return -1;
}

llong ans_max[maxn];
void cal_max(int u, int p) {
    cnt_child[u] = 1;
    ans_max[u] = 0;
    for (auto [v, d]: gr[u]) {
        if (v == p) continue;
        cal_max(v, u);
        cnt_child[u] += cnt_child[v];
        ans_max[u] += ans_max[v];
        ans_max[u] += 1ll * d * cnt_child[v];
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> k; n = 2 * k;
        rep1(i, n) gr[i].clear();
        rep(i, n - 1) {
            int u, v, d; cin >> u >> v >> d;
            gr[u].emplace_back(v, d);
            gr[v].emplace_back(u, d);
        }

        cal_min(1, 1);
        dfs_count_child(1, 1);
        int cen = find_centroid(1);
        cal_max(cen, cen);
        cout << ans_min[1].xx << ' ' << ans_max[cen] << '\n';
    }

    return 0;
}