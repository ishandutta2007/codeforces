#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MX = 512;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    for(; b; grow(a, a), b>>=1)
        if(b&1) grow(res, a);
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

// assuming that it always has a solution
vector<int> gauss(vector<vector<int>> a){
    int n = a.size(), m = a[0].size()-1;
    vector<int> where(m, -1);
    for(int col = 0, row = 0; col<m && row<n; ++col){
        int sel = row;
        for(int i = row; i<n; ++i)
            if(a[i][col]>a[sel][col]) sel = i;
        if(a[sel][col]==0) continue;
        for(int i = col; i<=m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
        for(int i = 0; i<n; ++i)
            if(i != row){
                int c = mul(a[i][col], inv(a[row][col]));
                for(int j = col; j<=m; ++j)
                    dec(a[i][j], mul(a[row][j], c));
            }
        ++row;
    }
    vector<int> ans(m, 0);
    for(int i = 0; i<m; ++i)
        if(where[i] != -1)
            ans[i] = mul(a[where[i]][m], inv(a[where[i]][i]));
    return ans;
}

int n, m, g[N], cnt[MX];
vector<int> adj[N], order;
bool vis[N];

void dfs(int v){
    vis[v] = 1;
    for(auto u : adj[v])
        if(!vis[u]) dfs(u);
    order.push_back(v);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; ++i){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
    }
    for(int i = 0; i<n; ++i)
        if(!vis[i]) dfs(i);
    memset(vis, 0, sizeof vis);
    for(auto v : order){
        for(auto u : adj[v]){
            vis[g[u]] = 1;
            while(vis[g[v]]) ++g[v];
        }
        for(auto u : adj[v])
            vis[g[u]] = 0;
        cnt[g[v]]++;
    }
    for(int i = 0; i<MX; ++i)
        grow(cnt[i], inv(n+1));
    vector<vector<int>> a(MX, vector<int>(MX+1, 0));
    for(int i = 0; i<MX; ++i){
        for(int j = 0; j<MX; ++j){
            a[i][j] = cnt[i^j];
            if(i==j) dec(a[i][j], 1);
        }
        if(i==0) a[i][MX] = inv(n+1);
    }
    cout << add(gauss(a)[0], 1) << '\n';
}