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
const int MOD=Mod;
 
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
int t,n,m,a,b,c,cost[maxn],sum[maxn],u,v,dist[maxn][3],ans;
vector<int> adj[maxn];
queue<int> q;
bool vis[maxn];

void bfs(int x, int y){
	rep(n) vis[i]=false;
	q.push(x);
	vis[x]=true;
	dist[x][y]=0;
	while(!q.empty()){
		int u=q.front();
		rep(sz(adj[u])){
			int v=adj[u][i];
			if(vis[v]) continue;
			dist[v][y]=dist[u][y]+1;
			vis[v]=true;
			q.push(v);
		}
		q.pop();
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> a >> b >> c;
		a--,b--,c--;
		rep(m) cin >> cost[i];
		sort(cost,cost+m);
		sum[0]=0;
		rep(m) sum[i+1]=sum[i]+cost[i];
		rep(n) adj[i].clear();
		rep(m){
			cin >> u >> v;
			u--,v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs(a,0);
		bfs(b,1);
		bfs(c,2);
		ans=4e18;
		rep(n){
			if(dist[i][0]+dist[i][1]+dist[i][2]>m) continue;
			ans=min(ans,sum[dist[i][1]]+sum[dist[i][0]+dist[i][1]+dist[i][2]]);
		}
		print1(ans);
	}
	return 0;
}