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

#define maxn 101010
#define maxbit 70
int n;
llong a[maxn];
vector<int> group[maxbit];

vector<int> gr[maxn];
int dis[maxn];
int vis[maxn] = {0};
int YES = 0;

int find_cycle_dis(int src, int dst) {
    ++YES;
    queue<int> qu;
    for (qu.push(src), dis[src] = 0; len(qu); qu.pop()) {
        int u = qu.front();
        if (u == dst) return dis[dst] + 1;
        for (auto v: gr[u]) {
            if (u == src and v == dst) continue;
            if (vis[v] == YES) continue;
            vis[v] = YES;
            dis[v] = dis[u] + 1;
            qu.push(v);
        }
    }
    return INT_MAX;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        for (llong u = a[i], f = 0; u > 0; u >>= 1, ++f) {
            if (u & 1) group[f].emplace_back(i);
        }
    }

    rep(i, maxbit) {
        if (len(group[i]) >= 3) {
            cout << 3;
            return 0;
        }
        if (len(group[i]) <= 1) continue;
        int u = group[i][0], v = group[i][1];
        gr[u].emplace_back(v);
        gr[v].emplace_back(u);
    }

    int ans = INT_MAX;
    rep(u, n) {
        for (auto v: gr[u]) 
            ans = min(ans, find_cycle_dis(u, v));
    }

    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}