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

vector<pii> v[N];
array<int,3> edgs[N];

vector<vector<int>> mn;

vector<pii> g[N];

int root;
void dfs(int z,int p,int w = INF){
	mn[root][z] = w;
	for(pii x:g[z]){
		if(x.fr == p){
			continue;
		}
		dfs(x.fr,z,min(w,x.sc));
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	int xrr = 0;
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		v[x].pb({y,w});
		v[y].pb({x,w});
		edgs[i] = {w,x,y};
		xrr ^= w;
	}
	sort(edgs,edgs+m);
	
	
	int ans = 0;
	// just simply make mst
	set<int> unvis,vis;
	rep(i,2,n+1){
		unvis.insert(i);
	}
	set<pair<int, pii>> s; // prim algo
	s.insert({0,{1,-1}});
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(cur);
		int z = cur.sc.fr;
		int par = cur.sc.sc;
		if(vis.count(z)){
			continue;
		}
		
		if(par != -1){
			g[z].pb({par,cur.fr});
			g[par].pb({z,cur.fr});
		}
		
		ans += cur.fr;
		vis.insert(z);
		set<int> adj;
		for(pii x:v[z]){
			adj.insert(x.fr);
		}
		vector<int> uv(all(unvis));
		for(int x:uv){
			if(!adj.count(x)){
				unvis.erase(x);
				adj.erase(x);
				s.insert({0,{x,z}});
			}
		}
		for(pii x:v[z]){
			if(!vis.count(x.fr) && adj.count(x.fr)){
				s.insert({x.sc,{x.fr,z}});
			}
		}
	}
	
	
	if(n > 1000){
		cout << ans << "\n";
		return;
	}
	
	// n < 1000, make mst and then find min edg with replaceable 0
	// g is the mst graph
	
	int ze = 0;
	rep(i,1,n+1){
		for(auto x:g[i]){
			if(x.sc == 0) ze++;
		}
	}
	ze /= 2;
	if(m + ze != n * (n - 1) / 2){
		cout << ans << "\n";
		return;
	}
	
	mn.resize(n+1,vector<int>(n+1));
	rep(i,1,n+1){
		root = i;
		dfs(root,0);
	}
	
	rep(i,0,m){
		int x = edgs[i][1], y = edgs[i][2], w = edgs[i][0];
		if(mn[x][y] == 0){
			ans += min(xrr,w);
			break;
		}
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