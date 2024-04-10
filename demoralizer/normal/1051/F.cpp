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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

int dis[N],vis[N];
vector<pii> v[N];
set<int> s;

const int H = 17;
int par[N][H+1], lvl[N];
void dfs(int z, int p){
	vis[z] = 1;
	lvl[z] = lvl[p] + 1;
	par[z][0] = p;
	for (int i = 1; i <= H; ++i){
		par[z][i] = par[par[z][i-1]][i-1];
	}
	for(pii x:v[z]){
		if(x.fr==p)continue;
		if(vis[x.fr]){
			s.insert(z);
			s.insert(x.fr);
			continue;
		}
		dis[x.fr] = dis[z] + x.sc;
		dfs(x.fr,z);
	}
}

int lca(int x, int y) {
	if (lvl[x] < lvl[y]) swap(x, y);
	for (int i = H; i >= 0; i--){
		if (lvl[x] - (1<<i) >= lvl[y]){
			x = par[x][i];
		}
	}
	if (x == y) return x;
	for (int i = H; i >= 0; i--){
		if (par[x][i] != par[y][i]){
			x = par[x][i], y = par[y][i];
		}
	}
	return par[x][0];
}

vector<vector<int>> val;

void dijkstra(int root){
	val.pb(vector<int>(N,INF));
	auto &dis = val.back();
	set<pii> s;
	s.insert({0,root});
	dis[root] = 0;
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(s.begin());
		int z = cur.sc;
		for(pii x:v[z]){
			int d = x.sc + dis[z];
			if(dis[x.fr] <= d) continue;
			s.erase({dis[x.fr],x.fr});
			dis[x.fr] = d;
			s.insert({dis[x.fr],x.fr});
		}
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,0,m){
		int x,y,z;
		cin >> x >> y >> z;
		v[x].pb({y,z});
		v[y].pb({x,z});
	}
	
	dfs(1,0);
	
	for(int x:s){
		dijkstra(x);
	}
	
	int q;
	cin >> q;
	rep(i,0,q){
		int x,y;
		cin >> x >> y;
		int ans = dis[x] + dis[y] - 2 * dis[lca(x,y)];
		// cout << lca(x,y) << " ";
		for(auto &dis:val){
			amin(ans,dis[x] + dis[y]);
		}
		cout << ans << "\n";
	}
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