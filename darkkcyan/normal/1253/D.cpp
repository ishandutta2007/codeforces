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
int n, m;

int dsu[maxn];
int find_set(int u) { return u == dsu[u] ? u : dsu[u] = find_set(dsu[u]); }

int min_dsu[maxn], max_dsu[maxn];
void join(int u, int v) {
    if (rand() & 1) swap(u, v);
    u = find_set(u); v = find_set(v);
    if (u == v) return ;
    dsu[u] = v;
    min_dsu[v] = min(min_dsu[v], min_dsu[u]);
    max_dsu[v] = max(max_dsu[v], max_dsu[u]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep1(i, n) {
        dsu[i] = min_dsu[i] = max_dsu[i] = i;
    }

    rep(i, m) {
        int u, v; cin >> u >> v;
        join(u, v);
    }

    vector<pair<int, int>> ranges;
    rep1(i, n) {
        if (find_set(i) == i)
            ranges.emplace_back(min_dsu[i], max_dsu[i]);
    }

    sort(ranges.begin(), ranges.end());

    int ans = 0;
    int cur_close = -1;
    for (auto i: ranges) {
        if (i.xx <= cur_close) {
            ++ans;
        }
        cur_close = max(cur_close, i.yy);
    }
    cout << ans;

    return 0;
}