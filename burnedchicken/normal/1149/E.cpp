#include <bits/stdc++.h>
#include <bits/extc++.h>

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
const int MOD=Mod;
const int maxn=200005;
//i_am_noob
int n,m,u,v,a[maxn],mex[maxn],b[maxn]={0},maxx=-inf;
vector<int> adj[maxn],radj[maxn],vec[maxn],order;
bool vis[maxn];

void rdfs(int u){
    vis[u]=true;
    for(auto v: radj[u]) if(!vis[v]) rdfs(v);
    order.pb(u);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(n) cin >> a[i];
    rep(m){
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),radj[v].pb(u);
    }
    memset(vis,0,sizeof(vis));
    rep(n) if(!vis[i]) rdfs(i);
    rep3(i,n-1,0){
        u=order[i];
        rep1(j,sz(adj[u])) vis[j]=false;
        for(auto v: adj[u]) vis[mex[v]]=true;
        mex[u]=sz(adj[u]);
        rep1(j,sz(adj[u])) if(!vis[j]){
            mex[u]=j;
            break;
        }
        vec[mex[u]].pb(u);
        b[mex[u]]^=a[u];
    }
    rep(n+1) if(b[i]) maxx=max(maxx,i);
    if(maxx==-inf){
        print1("LOSE");
        return 0;
    }
    for(auto v: vec[maxx]) if((a[v]^b[maxx])<a[v]){
        u=v;
        break;
    }
    a[u]^=b[maxx];
    b[maxx]=0;
    for(auto v: adj[u]) if(mex[v]<mex[u]){
        a[v]^=b[mex[v]];
        b[mex[v]]=0;
    }
    print1("WIN");
    rep(n) print0(a[i]);
    cout << "\n";
    return 0;
}