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

#define maxn 2020
int n;
int x[maxn], y[maxn];
llong c[maxn], k[maxn];

int dsu[maxn];
int findp(int u) { return u == dsu[u] ? u : dsu[u] = findp(dsu[u]); }
void join(int u, int v) {
    dsu[findp(u)] = findp(v);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) cin >> x[i] >> y[i];
    rep1(i, n) cin >> c[i];
    rep1(i, n) cin >> k[i];

    rep1(i, n) dsu[i] = i;
    vector<tuple<llong, int, int>> edge_costs;
    rep1(i, n) edge_costs.emplace_back(c[i], i, 0);
    rep1(i, n) 
        for (int f = i + 1; f <= n; ++f) {
            llong dis = abs(x[i] - x[f]) + abs(y[i] - y[f]);
            edge_costs.emplace_back(dis * (k[i] + k[f]), i, f);
        }
    sort(edge_costs.begin(), edge_costs.end());
    llong ans = 0;
    vector<int> stations;
    vector<tuple<int, int>> connections;
    for (auto [cost, u, v]: edge_costs) {
        if (findp(u) == findp(v)) continue;
        join(u, v);
        ans += cost;
        if (v == 0) stations.push_back(u);
        else connections.emplace_back(u, v);
    }

    cout << ans << '\n';
    cout << len(stations) << '\n';
    for (auto i: stations) cout << i << ' ';
    cout << '\n';
    cout << len(connections) << '\n';
    for (auto [u, v]: connections) cout << u << ' ' << v << '\n';

    return 0;
}