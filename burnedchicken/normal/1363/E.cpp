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
#define eps 1e-9
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
const int MOD=Mod2;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=200005;
//i_am_noob
int n,a[maxn],b[maxn],c[maxn],u,v,val[maxn],cnt[maxn],ans=0;
vector<int> adj[maxn];

void dfs(int u, int x){
    if(x>=0) if(a[u]>a[x]) a[u]=a[x];
    val[u]=b[u]-c[u];
    int tmp1=0,tmp2=0;
    if(val[u]==1) tmp1++;
    if(val[u]==-1) tmp2++;
    for(auto v:adj[u]) if(v!=x){
        dfs(v,u);
        if(val[v]>0) tmp1+=val[v];
        else tmp2+=-val[v];
        val[u]+=val[v];
    }
    cnt[u]=2*min(tmp1,tmp2);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i] >> b[i] >> c[i];
	if(accumulate(b,b+n,0)!=accumulate(c,c+n,0)){
        print1(-1);
        return 0;
	}
	rep(n-1){
	    cin >> u >> v;
	    u--,v--;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	dfs(0,-1);
	rep(n) ans+=a[i]*cnt[i];
	print1(ans);
	return 0;
}