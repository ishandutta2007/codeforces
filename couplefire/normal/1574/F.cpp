#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, m, k, cnt[N], dp[N];
set<array<int, 2>> edges; bool vis[N];
vector<int> good, adj[N], radj[N];

int dfs(int v){
    if(vis[v]) return 0;
    vis[v] = 1;
    if((int)radj[v].size()>1) return 0;
    if(!adj[v].size()) return 1;
    else if((int)adj[v].size()==1){
        int res = dfs(adj[v][0]);
        if(!res) return 0;
        return res+1;
    }
    return 0;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i<=n; ++i){
        int c; cin >> c;
        int prv = 0;
        for(int j = 1; j<=c; ++j){
            int a; cin >> a;
            if(prv && !edges.count({prv, a})){
                adj[prv].push_back(a);
                radj[a].push_back(prv);
                edges.insert({prv, a});
            }
            prv = a;
        }
    }
    for(int i = 1; i<=k; ++i)
        if(radj[i].empty()) cnt[dfs(i)]++;
    for(int i = 1; i<=k; ++i)
        if(cnt[i]) good.push_back(i);
    dp[0] = 1;
    for(int i = 1; i<=m; ++i)
        for(int x : good)
            if(i>=x) inc(dp[i], mul(dp[i-x], cnt[x]));
    cout << dp[m] << '\n';
}