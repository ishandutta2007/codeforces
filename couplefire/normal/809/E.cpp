#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;
const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    for(; b; grow(a, a), b >>= 1)
        if(b&1) grow(res, a);
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int n, arr[N], siz[N], phi[N];
int val1[N], val2[N], val3[N], tmp1[N], tmp2[N], ans;
vector<int> adj[N], fs[N];
bool vis[N];

void dfs1(int v, int p){
    siz[v] = 1;
    for(int u : adj[v])
        if(u != p && !vis[u])
            dfs1(u, v), siz[v] += siz[u];
}

int get(int v){
    dfs1(v, -1);
    int p = -1, num = siz[v];
    do{
        int nxt = -1;
        for(int u : adj[v])
            if(u != p && !vis[u])
                if(siz[u]*2 > num) nxt = u;
        p = v, v = nxt;
    } while(~v);
    return p;
}

void dfs2(int v, int p, int dep){
    for(int gd : fs[arr[v]]){
        inc(tmp1[gd], val1[gd]);
        inc(tmp2[gd], val2[gd]);
        inc(ans, mul(mul(val3[gd], phi[arr[v]]), mul(dep, tmp1[gd])));
        inc(ans, mul(mul(val3[gd], phi[arr[v]]), tmp2[gd]));
        for(int f : fs[gd])
            if(f != gd) dec(tmp1[f], tmp1[gd]), dec(tmp2[f], tmp2[gd]);
    }
    for(int gd : fs[arr[v]])
        tmp1[gd] = tmp2[gd] = 0;
    for(int u : adj[v])
        if(u != p && !vis[u])
            dfs2(u, v, dep+1);
}

void dfs3(int v, int p, int dep){
    for(int f : fs[arr[v]])
        inc(val1[f], phi[arr[v]]),
        inc(val2[f], mul(dep, phi[arr[v]]));
    for(int u : adj[v])
        if(u != p && !vis[u])
            dfs3(u, v, dep+1);
}

void dfs4(int v, int p){
    for(int f : fs[arr[v]])
        val1[f] = val2[f] = 0;
    for(int u : adj[v])
        if(u != p && !vis[u])
            dfs4(u, v);
}

void solve(int v){
    int c = get(v);
    for(int f : fs[arr[c]])
        inc(val1[f], phi[arr[c]]);
    for(int u : adj[c]){
        if(vis[u]) continue;
        dfs2(u, c, 1);
        dfs3(u, c, 1);
    }
    dfs4(c, -1);
    vis[c] = 1;
    for(int u : adj[c])
        if(!vis[u]) solve(u);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i<=n; i++)
        for(int j = i; j<=n; j+=i)
            fs[j].push_back(i);
    for(int i = 1; i<=n; i++)
        reverse(fs[i].begin(), fs[i].end());
    for(int i = 1; i<=n; i++)
        phi[i] = i;
    for(int i = 2; i<=n; i++)
        if(phi[i]==i)
            for(int j = i; j<=n; j+=i)
                phi[j] -= phi[j]/i;
    for(int i = 1; i<=n; i++)
        val3[i] = mul(i, inv(phi[i]));
    solve(0);
    grow(ans, 2);
    grow(ans, inv(n));
    grow(ans, inv(n-1));
    cout << ans << '\n';
}