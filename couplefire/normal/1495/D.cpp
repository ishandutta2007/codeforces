#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

pair<int,int> es[666];
int dis[406][406], ans[406][406];
const int mod = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        es[i] = {u, v};
        dis[u][v] = dis[v][u] = 1;
    }
    for(int i = 1; i <= n; ++i) dis[i][i] = 0;
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            if(i != j) {
                int cnt = 0;
                for(int k = 1; k <= n; ++k) {
                    if(i == k || j == k) continue;
                    if(dis[k][i] + dis[k][j] == dis[i][j]) {
                        ++cnt;
                        continue;
                    }
                }

                if(cnt != dis[i][j] - 1) continue;
            }
            vector<int> cnt(n + 1, 0);
            for(int k = 1; k <= m; ++k) {
                int u = es[k].first, v = es[k].second;
                if(dis[u][i] < dis[v][i]) swap(u, v);
                if(dis[u][i] - dis[v][i] == 1 && dis[u][j] - dis[v][j] == 1) {
                    assert(u != i && u != j);
                    cnt[u] += 1;
                }
            }
            ll res = 1;
            for(int k = 1; k <= n; ++k) if(k != i && k != j && dis[k][i] + dis[k][j] != dis[i][j]) res = res * cnt[k] % mod;
            ans[i][j] = ans[j][i] = res;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}