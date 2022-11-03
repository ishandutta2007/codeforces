#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const long long INF = 1e18;

int n, b;
vector<int> c, d, x;

vector<vector<int>> g;
vector<int> ts;
vector<vector<long long>> dp[2];

void BuildInfo(int v) {
    ts[v] = 1;
    for (int u : g[v]) {
        BuildInfo(u);
        ts[v] += ts[u];
    }
}

void BuildDp(int v) {
    for (int u : g[v]) {
        BuildDp(u);
    }
    vector<long long> buf[2];
    for (int up = 0; up < 2; ++up) {
        dp[up][v].assign(ts[v] + 1, INF);
        for (int nup = 0; nup < 2; ++nup) {
            if (up == 0 && nup == 1) {
                continue;
            }
            int cur = 0;
            buf[cur].assign(ts[v] + 1, INF);
            if (nup) {
                buf[cur][1] = c[v] - d[v];
            } else {
                buf[cur][0] = 0;
                buf[cur][1] = c[v];
            }
            int prevSize = 1;
            for (int u : g[v]) {
                int nxt = 1 - cur;
                buf[nxt].assign(ts[v] + 1, INF);
                for (int cp = 0; cp <= prevSize; ++cp) {
                    for (int cc = 0; cc <= ts[u]; ++cc) {
                        if (buf[cur][cp] != INF && dp[nup][u][cc] != INF) {
                            buf[nxt][cp + cc] = min(buf[nxt][cp + cc], buf[cur][cp] + dp[nup][u][cc]);
                        }
                    }
                }
                prevSize += ts[u];
                cur = nxt;
            }
            for (int i = 0; i <= ts[v]; ++i) {
                dp[up][v][i] = min(dp[up][v][i], buf[cur][i]);
            }
        }
    }
}

void Solve() {
    g.clear();
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        g[x[i]].push_back(i);
    }
    ts.resize(n);
    BuildInfo(0);
    for (int i = 0; i < 2; ++i) {
        dp[i].clear();
        dp[i].resize(n);
        for (int j = 0; j < n; ++j) {
            dp[i][j].resize(ts[j] + 1);
        }
    }
    BuildDp(0);
    for (int k = ts[0]; k >= 0; --k) {
        if (dp[1][0][k] <= b) {
            cout << k << endl;
            return;
        }
    }
    assert(false);
}

bool Read() {
    if (!(cin >> n >> b)) {
        return false;
    }
    c.resize(n);
    d.resize(n);
    x.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> d[i];
        if (i > 0) {
            cin >> x[i];
            --x[i];
        }
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}