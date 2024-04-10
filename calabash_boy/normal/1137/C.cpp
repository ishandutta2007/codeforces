#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
class SCC
{
public:
    int n,cnt; // cnt -> number of scc's formed
    vector<vector<int>> g, rg, sg, comp; // sg -> dag with all nodes compressed.
    vector<vector<pii>> out;
    vector<int> scc, order;
    vector<bool> vis;
    void reset(){
        g.clear(), rg.clear(), sg.clear(), comp.clear(), scc.clear(), vis.clear(), order.clear();
    }
    void init(int _n)
    {
        reset();
        out.resize(_n + 2);
        g.resize(_n + 2);
        rg.resize(_n + 2);
        sg.resize(_n + 2);
        scc.resize(_n + 2, 0);
        vis.resize(_n + 2, 0);
        comp.resize(_n + 2);
        n = _n,cnt = 0;
    }
    void add(int u,int v)
    {
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    void compute()
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                dfs1(i);
        }
        fill(all(vis), 0);
        for(int i=n-1;i>=0;i--)
        {
            if(!vis[order[i]])
                dfs2(order[i],++cnt);
        }
    }
    void dfs1(int u)
    {
        vis[u] = 1;
        for(int v: g[u])
        {
            if(!vis[v])
                dfs1(v);
        }
        order.push_back(u);
    }
    void dfs2(int u,int c)
    {
        vis[u] = 1;
        scc[u] = c;
        comp[c].pb(u);
        for(int v: rg[u])
        {
            if(!vis[v])
                dfs2(v,c);
            if(vis[v] && c!=scc[v]){
                sg[scc[v]].push_back(c);
                out[scc[v]].pb({v, u});
            }
        }
    }
} sc;
const int N = 1e5 + 5;
int dist[N];
bool vis[N];
int gg[N];
vector<int> g[N];
bool good;
int color[N];
void dfs(int u,int d,int c){
    vis[u] = 1;
    dist[u] = d;
    for(int v : g[u]){
        if(!vis[v] && sc.scc[v] == c){
            dfs(v, d + 1, c);
        }
    }
}
void dfs1(int u,int x,int p,int c){
    vis[u] = 1;
    color[u] = x;
    for(int v : g[u]){
        if(!vis[v] && sc.scc[v] == c){
            dfs1(v, (x + 1) % p, p, c);
        }
        else if(vis[v] && sc.scc[v] == c){
            if(color[v] != (x + 1) % p) good = 0;
        }
    }
}
int val[N][55];
int dp[N][55];
string s[N];
int d;
int solve(int u,int cd){
    if(dp[u][cd] != -1){
        return dp[u][cd];
    }
    int ans = 0;
    for(pii x : sc.out[u]){
        int d1 = (cd + dist[x.fi]) % gg[u];
        while(d1 < d){
            int d2 = (d1 + 1) % gg[sc.scc[x.se]];
            int d3 = (d2 + dist[x.se]) % gg[sc.scc[x.se]];
            ans = max(ans, solve(sc.scc[x.se], d3));
            d1 += gg[u];
        }
    }
    ans += val[u][cd];
    return dp[u][cd] = ans;
}
void solve(){
    int n, m;
    cin >> n >> m >> d;
    sc.init(n);
    fr(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        sc.add(u, v);
    }
    fr(i, 1, n){
        cin >> s[i];
    }
    sc.compute();
    fr(i, 1, sc.cnt){
        dfs(sc.comp[i][0], 0, i);
    }
    fr(i, 1, sc.cnt){
        gg[i] = 1;
    }
    for(int p = 1; p <= d; p++){
        fr(i, 1, sc.cnt){
            for(int u : sc.comp[i]){
                vis[u] = 0;
            }
            good = 1;
            dfs1(sc.comp[i][0], 0, p, i);
            if(good)
                gg[i] = max(gg[i], __gcd(d, p));
        }
    }
    fr(i, 1, sc.cnt){
        fr(j, 0, gg[i] - 1){
            for(int u : sc.comp[i]){
                int idx = (j + dist[u]) % gg[i];
                bool p = 0;
                while(idx < d){
                    p |= (s[u][idx] == '1');
                    idx += gg[i];
                }
                val[i][j] += p;
            }
        }
    }
    fill(vis + 1, vis + n + 1, 0);
    fr(i, 1, sc.cnt){
        fr(j, 0, d - 1){
            dp[i][j] = -1;
        }
    }
    int c = sc.scc[1];
    int dd = dist[1] % gg[c];
    cout << solve(c, dd);
}
signed main(){
    IO;
    int t = 1;
    fr(tt, 1, t){
        solve();
    }
    return 0;
}