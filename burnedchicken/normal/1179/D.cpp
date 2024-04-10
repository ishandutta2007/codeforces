#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=500005;
//i_am_noob
int n,u,v,ans=inf,siz[maxn],dp[maxn];
vector<int> adj[maxn];

void dfs(int u, int pa){
    if(sz(adj[u])==1){
        dp[u]=siz[u]=1;
        return;
    }
    dp[u]=inf;
    siz[u]=1;
    for(auto v: adj[u]) if(v!=pa){
        dfs(v,u);
        siz[u]+=siz[v];
    }
    for(auto v: adj[u]) if(v!=pa) dp[u]=min(dp[u],dp[v]+(siz[u]-siz[v])*(siz[u]-siz[v]));
}

void dfs2(int u, int pa){
    vector<pii> vec,vec1;
    for(auto v: adj[u]) if(v!=pa) vec1.pb({siz[v],dp[v]+siz[v]*siz[v]-2*n*siz[v]});
    sort(all(vec1));
    rep(sz(vec1)){
        if(i==0||vec1[i-1].first<vec1[i].first) vec.pb(vec1[i]);
        else ans=min(ans,vec1[i-1].second+vec1[i].second+n*n+2*vec1[i-1].first*vec1[i].first);
    }
    rep(sz(vec)) rep2(j,i+1,sz(vec)) ans=min(ans,vec[i].second+vec[j].second+n*n+2*vec[i].first*vec[j].first);
    for(auto v: adj[u]) if(v!=pa) dfs2(v,u);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n-1){
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    if(n==2){
        print1(2);
        return 0;
    }
    rep(n) if(sz(adj[i])>1){
        dfs(i,-1);
        rep1(j,n) if(j!=i) ans=min(ans,dp[j]+(n-siz[j])*(n-siz[j]));
        dfs2(i,-1);
        print1(n*(n-1)-(ans-n)/2);
        return 0;
    }
    return 0;
}