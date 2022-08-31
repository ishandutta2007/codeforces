#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

#define min     max

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
#define amin    amax

const long long INF=0;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

vector<array<int,3>> g[N], edg;
vector<pii> v[N];
int vis[N];


const int H = 18;
int par[N][H+1], lvl[N], mn[N][H+1];
void dfs(int z, int p, int w){
	lvl[z] = lvl[p] + 1;
	par[z][0] = p;
	mn[z][0] = w;
	for (int i = 1; i <= H; ++i){
		par[z][i] = par[par[z][i-1]][i-1];
		mn[z][i] = min(mn[z][i-1],mn[par[z][i-1]][i-1]);
	}
	for(pii x:v[z]){
		if(x.fr==p)continue;
		dfs(x.fr,z,x.sc);
	}
}

int mnw(int x, int y) {
	if (lvl[x] < lvl[y]) swap(x, y);
	int ans = INF;
	for (int i = H; i >= 0; i--){
		if (lvl[x] - (1<<i) >= lvl[y]){
			amin(ans,mn[x][i]);
			x = par[x][i];
		}
	}
	if (x == y) return ans;
	for (int i = H; i >= 0; i--){
		if (par[x][i] != par[y][i]){
			amin(ans,mn[x][i]);
			amin(ans,mn[y][i]);
			x = par[x][i], y = par[y][i];
		}
	}
	amin(ans,mn[x][0]);
	amin(ans,mn[y][0]);
	return ans;
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({w,v,u});
		g[v].pb({w,u,v});
		edg.pb({u,v,w});
	}
	set<array<int,3>> s;
	vis[1] = 1;
	s.insert(all(g[1]));
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(s.begin());
		if(vis[cur[1]]) continue;
		vis[cur[1]] = 1;
		
		v[cur[2]].pb({cur[1],cur[0]});
		v[cur[1]].pb({cur[2],cur[0]});
		
		s.insert(all(g[cur[1]]));
	}
	
	dfs(1,0,INF);
	int ans = 0;
	for(auto x : edg){
		if(par[x[0]][0] == x[1] || par[x[1]][0] == x[0]){
			continue;
		}
		// cout << x[0] << " " << x[1] << " " << x[2] << " " << mnw(x[0],x[1]) << "\n";
		if(mnw(x[0],x[1]) == x[2]) ans++;
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}