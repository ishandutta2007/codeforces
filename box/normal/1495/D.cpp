#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
const int MOD = 998244353;

bool ed[405][405];
bool un[405][405];
int dis[405][405];
int res[405][405];
int cnt[405];
vector<int> elist[405];

int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n, m; cin >> n >> m;
    rep1(i, n) rep1(j, n) dis[i][j] = 1e9, res[i][j] = -1;
    rep1(i, n) dis[i][i] = 0;
    rep(i, m) {
        int u, v; cin >> u >> v;
        elist[u].push_back(v);
        elist[v].push_back(u);
        ed[u][v] = ed[v][u] = 1;
        dis[u][v] = dis[v][u] = 1;
    }
    rep1(k, n) rep1(i, n) rep1(j, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    rep1(i, n) rep1(j, n) {
        rep(k, n+1) cnt[k] = 0;
        rep1(k, n) if(dis[i][k] + dis[k][j] == dis[i][j]) cnt[dis[i][k]]++;
        un[i][j] = 1;
        rep(k, n+1) if(cnt[k] > 1) un[i][j] = 0;
    }
    rep1(i, n) rep1(j, n) {
        if(res[j][i] != -1) {
            res[i][j] = res[j][i];
            continue;
        }
        if(!un[i][j]) {
            res[i][j] = 0;
            continue;
        }
        int ans = 1;
        rep1(k, n) {
            if(dis[i][k] + dis[k][j] == dis[i][j]) continue;
            int cnt = 0;
            for(int f:elist[k])
                if(dis[f][i] + 1 == dis[k][i] && dis[f][j] + 1 == dis[k][j]) cnt++;
            ans = 1ll * ans * cnt % MOD;
            if(!ans) break;
        }
        res[i][j] = ans;
    }
    rep1(i, n) rep1(j, n) cout << res[i][j] << " \n"[j==n];
    return 0;
}