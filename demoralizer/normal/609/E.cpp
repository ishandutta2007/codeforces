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

const int N=2e5+5;

const int H = 18;
int par[N][H+1], val[N][H+1], lvl[N];
vector<pii> v[N];
vector<pii> g[N];
void dfs(int z, int p,int w){
	lvl[z] = lvl[p] + 1;
	par[z][0] = p;
	val[z][0] = w;
	for (int i = 1; i <= H; ++i){
		par[z][i] = par[par[z][i-1]][i-1];
		val[z][i] = max(val[z][i-1],val[par[z][i-1]][i-1]);
	}
	for(pii x:v[z]){
		if(x.fr==p)continue;
		dfs(x.fr,z,x.sc);
	}
}

int lca(int x, int y) {
	int ans = 0;
	if (lvl[x] < lvl[y]) swap(x, y);
	for (int i = H; i >= 0; i--){
		if (lvl[x] - (1<<i) >= lvl[y]){
			amax(ans,val[x][i]);
			x = par[x][i];
		}
	}
	if (x == y) return ans;
	for (int i = H; i >= 0; i--){
		if (par[x][i] != par[y][i]){
			amax(ans,val[x][i]);
			amax(ans,val[y][i]);
			x = par[x][i], y = par[y][i];
		}
	}
	return max({ans,val[x][0],val[y][0]});
}

pair<pii, int> edg[N];
int vis[N];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		cin>>edg[i];
		g[edg[i].fr.fr].pb({edg[i].fr.sc,edg[i].sc});
		g[edg[i].fr.sc].pb({edg[i].fr.fr,edg[i].sc});
	}
	
	set<pair<int, pii>> s;
	for(pii x:g[1]){
		s.insert({x.sc,{1,x.fr}});
	}
	vis[1] = 1;
	int tot = 0;
	while(sz(s)){
		auto cur = *s.begin();
		s.erase(s.begin());
		if(vis[cur.sc.sc]) continue;
		vis[cur.sc.sc] = 1;
		v[cur.sc.fr].pb({cur.sc.sc,cur.fr});
		v[cur.sc.sc].pb({cur.sc.fr,cur.fr});
		tot+=cur.fr;
		for(pii x:g[cur.sc.sc]){
			s.insert({x.sc,{cur.sc.sc,x.fr}});
		}
	}
	
	dfs(1,0,0);
	
	rep(i,0,m){
		int x=edg[i].fr.fr;
		int y=edg[i].fr.sc;
		int w=edg[i].sc;
		int wt = lca(x,y);
		amin(wt,w);
		cout<<tot-wt+w<<"\n";
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