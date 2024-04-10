#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
const ll OO = (ll) 1e18;
int n;
int m;
int a[3];
ll s[N];
int d[3][N];
vector<int> g[N];

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                cin >> n >> m >> a[0] >> a[1] >> a[2];
                for (int i = 1; i <= m; i++) {
                        cin >> s[i];
                }
                sort(s + 1, s + m + 1);
                for (int i = 2; i <= m; i++) {
                        s[i] += s[i - 1];
                }
                for (int i = 1; i <= n; i++) {
                        g[i].clear();
                }
                for (int i = 1; i <= m; i++) {
                        int x, y;
                        cin >> x >> y;
                        g[x].push_back(y);
                        g[y].push_back(x);
                }
                for (int j = 0; j <= 2; j++) {
                        for (int i = 1; i <= n; i++) {
                                d[j][i] = -1;
                        }
                        d[j][a[j]] = 0;
                        queue<int> q;
                        q.push(a[j]);
                        while (!q.empty()) {
                                int x = q.front();
                                q.pop();
                                for (auto &y : g[x]) {
                                        if (d[j][y] == -1) {
                                                d[j][y] = 1 + d[j][x];
                                                q.push(y);
                                        }
                                }
                        }
                }
                ll sol = OO;
                for (int i = 1; i <= n; i++) {
                        if (d[0][i] + d[1][i] + d[2][i] <= m) {
                                sol = min(sol, s[d[0][i] + d[1][i] + d[2][i]] + s[d[1][i]]);
                        }
                }
                cout << sol << "\n";
        }

}