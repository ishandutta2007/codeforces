#include "bits/stdc++.h"
using namespace std;
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

int n,m,d;
string s[N];
vector<vector<int>> g,rg;

int hsh(int x, int y){
	return d * x + y;
}

bool check(int x){
	int ver = x / d;
	int day = x % d;
	return (s[ver][day] == '1');
}

bool vis[50*N];
int head[50*N], val[50*N], dp[50*N];
vector<int> order, comp;

void dfs1(int z){
	vis[z] = 1;
	int j = ((z%d)+1)%d;
	for(int y:g[z/d]){
		int x = hsh(y,j);
		if(vis[x]) continue;
		dfs1(x);
	}
	order.pb(z);
}

void dfs2(int z){
	vis[z] = 1;
	int j = ((z%d)-1+d)%d;
	for(int y:rg[z/d]){
		int x = hsh(y,j);
		if(vis[x]) continue;
		dfs2(x);
	}
	comp.pb(z);
}

int dfs3(int z){
	if(vis[z]) return dp[z];
	vis[z] = 1;
	// int j = ((z%d)+1)%d;
	for(int x:g[z]){
		// int x = hsh(y,j);
		amax(dp[z], dfs3(x));
	}
	dp[z] += val[z];
	return dp[z];
}
vector<pii> edges;

void solve(){
	cin >> n >> m >> d;
	g.resize(d*(n+1));
	rg.resize(d*(n+1));
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
			g[x].pb(y);
			rg[y].pb(x);
			// g[hsh(x,j)].pb(hsh(y,(j+1)%d));
			// rg[hsh(y,(j+1)%d)].pb(hsh(x,j));
		edges.pb({x,y});
	}
	rep(i,1,n+1){
		cin >> s[i];
	}
	
	rep(i,1,n+1){
		rep(j,0,d){
			int x = hsh(i,j);
			if(vis[x]) continue;
			dfs1(x);
		}
	}
	
	mem0(vis);
	while(sz(order)){
		int x = order.back();
		order.ppb();
		if(vis[x]) continue;
		
		comp.clear();
		dfs2(x);
		
		// comp contains SCC
		set<int> s;
		for(int x:comp){
			if(check(x)){
				s.insert(x / d);
			}
			head[x] = comp[0];
		}
		val[comp[0]] = sz(s);
	}
	
	g.clear();
	g.resize(d*(n+1));
	for(pii z:edges){
		int x = z.fr, y = z.sc;
		rep(j,0,d){
			int u = hsh(x,j), v = hsh(y,(j+1)%d);
			u = head[u];
			v = head[v];
			g[u].pb(v);
		}
	}
	
	int ans = 0;
	mem0(vis);
	
	cout << dfs3(head[hsh(1,0)]);
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