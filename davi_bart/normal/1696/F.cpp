#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool k[107][107][107];
int N;
vector<pair<int, int> > ans;
vector<bool> vis(109);
bool ok = 1;
bool check() {
    vector<int> v[N + 2];
    for (auto [a, b] : ans) {
        v[a].pb(b);
        v[b].pb(a);
    }
    vector<vector<int> > d(N + 2, vector<int>(N + 2, 0));
    for (int i = 0; i < N; i++) {
        vector<bool> vv(N + 2, 0);
        queue<pair<int, int> > q;
        q.push({i, 0});
        while (!q.empty()) {
            auto [pos, dd] = q.front();
            q.pop();
            if (vv[pos]) continue;
            vv[pos] = 1;
            d[i][pos] = dd;
            for (int x : v[pos]) q.push({x, dd + 1});
        }
    }
    // cout << "NNNN " << N << endl;
    // return 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int x = 0; x < N; x++) {
                // if (x == i || x == j) continue;
                if (d[i][x] == d[j][x] && k[i][j][x] == 0) {
                    // cout << i << " " << j << " " << x << " " << d[i][x] << endl;
                    return 0;
                }
                if (d[i][x] != d[j][x] && k[i][j][x]) {
                    // cout << i << " " << j << " " << x << " " << d[i][x] << endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}
void solve(int pos, int par) {
    if (!ok) return;
    vis[pos] = 1;
    for (int i = 0; i < N; i++) {
        if (i != par && i != pos && k[i][par][pos]) {
            if (vis[i]) {
                continue;
            }
            ans.pb({i, pos});
            solve(i, pos);
        }
    }
}
void solve() {
    cin >> N;
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            for (int z = 0; z < N + 2; z++) {
                k[i][j][z] = 0;
            }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            string a;
            cin >> a;
            for (int x = 0; x < N; x++) {
                k[i][i + j + 1][x] = k[i + j + 1][i][x] = (a[x] == '1');
            }
        }
    }
    for (int i = 1; i < N; i++) {
        ans.clear();
        ok = 1;
        fill(vis.begin(), vis.begin() + N + 3, 0);

        solve(0, i);
        solve(i, 0);
        ans.pb({0, i});
        if (ans.size() == N - 1 && ok && check()) {
            cout << "YES\n";
            for (auto [a, b] : ans) cout << a + 1 << " " << b + 1 << '\n';
            return;
        }
    }
    cout << "NO\n";
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}