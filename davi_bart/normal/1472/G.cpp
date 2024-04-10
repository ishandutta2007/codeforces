#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define int ll
using namespace std;
vector<int> d(200010, -1);
vector<int> v[200010];
int memo[200010][2];
bool vis[200010][2];
int ans(int pos, bool x) {
    if (vis[pos][x]) return memo[pos][x];
    vis[pos][x] = 1;
    memo[pos][x] = d[pos];
    if (!x) return memo[pos][x];

    for (int y : v[pos]) {
        if (d[y] <= d[pos] && x)
            memo[pos][x] = min(memo[pos][x], d[y]);
        else
            memo[pos][x] = min(memo[pos][x], ans(y, x));
    }
    return memo[pos][x];
}
void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N + 10; i++) {
        d[i] = -1;
        v[i].clear();
        memo[i][0] = memo[i][1] = vis[i][0] = vis[i][1] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
    }
    queue<pair<int, int> > q;
    q.push({1, 0});
    while (!q.empty()) {
        auto [pos, dd] = q.front();
        q.pop();
        if (d[pos] != -1) continue;
        d[pos] = dd;
        for (int x : v[pos]) q.push({x, dd + 1});
    }
    for (int i = 1; i <= N; i++) {
        cout << ans(i, 1) << " ";
    }
    cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}