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
#define eps 1e-32
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=300005;
//i_am_noob
int n,a[maxn],u,v,fa[maxn],val[maxn],maxx=-4e18,k=0;
vector<int> adj[maxn];
bool b1[maxn]={false},b2[maxn];

void dfs(int u, int x){
    fa[u]=x;
    val[u]=a[u];
    for(auto v:adj[u]) if(v!=x){
        dfs(v,u);
        if(val[v]>0) {val[u]+=val[v];b1[v]=true;}
    }
}

void dfs2(int u, int x){
    b2[u]=false;
    for(auto v:adj[u]) if(v!=x){
        dfs2(v,u);
        if(b1[v]&&(b2[v]||val[v]==maxx)) b2[u]=true;
    }
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i];
    rep(n-1){
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0,-1);
    rep(n) maxx=max(maxx,val[i]);
    dfs2(0,-1);
    rep(n) if((!b2[i])&&val[i]==maxx) k++;
    print2(maxx*k,k);
	return 0;
}