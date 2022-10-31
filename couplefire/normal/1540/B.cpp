#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) grow(res, a);
        grow(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int n;
vector<int> adj[N];
int dep[N], up[N][20], tin[N], tout[N], timer, d[N][N], lca[N][N];
int prob[N][N], win[N][N], ans;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i<20; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    for(auto u : adj[v])
        if(u != p) dep[u] = dep[v]+1, dfs(u, v);
    tout[v] = timer;
}

bool isPar(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA(int u, int v){
    if(isPar(u, v)) return u;
    if(isPar(v, u)) return v;
    for(int i = 19; i>=0; i--)
        if(!isPar(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int dist(int u, int v){
    return dep[u]+dep[v]-2*dep[LCA(u, v)];
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0);
    prob[0][0] = 1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(i == 0 && j == 0) continue;
            if(i) inc(prob[i][j], prob[i-1][j]);
            if(j) inc(prob[i][j], prob[i][j-1]);
            grow(prob[i][j], inv(2));
        }
    }
    fill(win[0], win[0]+N, 1);
    for(int i = 1; i<N; i++){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<j; k++)
                inc(win[i][j], prob[i-1][k]);
            grow(win[i][j], inv(2));
        }
    }
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            d[i][j] = dist(i, j),
            lca[i][j] = LCA(i, j);
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = 0; k<n; k++){
                int bruh = lca[i][k];
                if(dep[lca[j][k]] > dep[bruh]) bruh = lca[j][k];
                if(dep[lca[i][j]] > dep[bruh]) bruh = lca[i][j];
                inc(ans, win[d[bruh][j]][d[bruh][i]]);
            }
        }
    }
    grow(ans, inv(n));
    cout << ans << endl;
}