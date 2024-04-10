#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 100005
#define MAXK 205

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, k;
vector<int> adj[MAXN];
int dp[MAXN][MAXK], tmp[MAXK], siz[MAXN], ans[MAXK], fact[MAXK];
int s[MAXK][MAXK], res;

void dfs(int v, int p){
    siz[v] = 1, dp[v][0] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs(u, v);
        for(int i = 0; i<=k; i++) tmp[i] = dp[v][i];
        inc(dp[v][0], dp[u][0]);
        for(int i = 1; i<=min(siz[u], k); i++) inc(dp[v][i], add(dp[u][i], dp[u][i-1]));
        for(int i = 0; i<=min(siz[v], k); i++){
            for(int j = 0; j<=min(siz[u], k-i); j++){
                int val = mul(tmp[i], dp[u][j]);
                inc(dp[v][i+j], val); inc(ans[i+j], val);
                inc(dp[v][i+j+1], val); inc(ans[i+j+1], val);
            }
        }
        siz[v] += siz[u];
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1; i<MAXK; i++) fact[i] = mul(fact[i-1], i);
    s[0][0] = 1;
    for(int i = 1; i<MAXK; i++){
        s[i][i] = 1;
        for(int j = 1; j<i; j++) inc(s[i][j], add(s[i-1][j-1], mul(s[i-1][j], j)));
    }
    cin >> n >> k;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 0; i<=k; i++) inc(res, mul(mul(fact[i], s[k][i]), ans[i]));
    cout << res << endl;
}