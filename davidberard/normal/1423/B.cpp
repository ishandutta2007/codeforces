#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define pb(a) push_back(a)
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = 998244353;
ld eps = 1e-13;


// by henryx

#define N 100100

namespace n5{

	struct Edge { int v, r; ll f, c, p; };
	vector<Edge> adj[N]; int sz[N]; ll mc;
	vector<Edge> mcf_edges; // for mcf on large graphs with negative costs
	void init(int n=N) {
	  mc=0; fill(sz,sz+n,0); fill(adj,adj+n,vector<Edge>()); }
	void add_edge(int a, int b, ll c=1, ll p=0) { mc = max(mc,c); // scaling
	  // mcf_edges.push_back({b,a,0,c,p});
		adj[a].push_back({b,sz[b]++,0,c,p});
		adj[b].push_back({a,sz[a]++,0,0,-p}); }
		
		
	int L[N], cur[N], Q[N];
	bool bfs(int s, int t, ll lim=1) {
	  memset(cur, 0, sizeof cur);
	  fori(N){
	  	L[i] = INF;
	  }
	  int f,b; Q[f=b=0] = s; L[s] = 0;
	  while(f<=b && L[t]==INF) { int u = Q[f++];
	    for(const Edge& e:adj[u]) if(L[e.v] == INF && e.c-e.f >= lim) {
	      Q[++b] = e.v; L[e.v] = L[u]+1; } } return L[t] < INF; }
	ll dfs(int u, int t, ll f) { if (u == t || !f) return f;
	  for (int i = cur[u]; i < sz[u]; cur[u] = ++i) { Edge& e = adj[u][i];
	    if(e.f<e.c && L[e.v]==L[u]+1) {
	      if(ll cf = dfs(e.v, t, min(e.c-e.f, f))) {
		e.f += cf; adj[e.v][e.r].f -= cf; return cf; } } } return 0; }
	ll flow(int s, int t, bool scaling=0) {ll inf=numeric_limits<ll>::max();
	  ll res = 0; for(ll lim=(scaling?mc:1); lim; lim/=2) {
	    while(bfs(s,t,lim))while(ll cf=dfs(s,t,inf))res += cf;} return res;}
		
}				

bool J(vector<ll>& a, vector<ll>& b){
	return a[2] < b[2];
}

void deal(){
      ll n, m;
	cin>>n>>m;
	
	vector<vector<ll> > edges;
	
	fori(m){
		ll ui, vi, ci;
		cin>>ui>>vi>>ci;
		edges.pb(vector<ll>({ui, vi, ci}));
	}
	
	
	sort(edges.begin(), edges.end(), J);
	
	
	
	
	ll lo = 1, hi = m+1;
	while(lo < hi){
		ll mid = (lo+hi)/2;
		
		n5::init(2*n + 14);
		ll s = 2*n + 10, t = 2*n+9;
	
		for(ll i = 1; i<=n; i++){
			n5::add_edge(s, i, 1);
			n5::add_edge(n+1+i, t, 1);
		}
		fori(mid){
			ll ui = edges[i][0], vi = edges[i][1];
			n5::add_edge(ui, n+1+vi);
		}
		
		ll cur = n5::flow(s, t);
		if(cur == n){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	if(lo == m+1){
		cout<<-1;
	}
	else{
		cout<<edges[lo-1][2];
	}
}
 
 
int main(){
 	cin.tie(0);
 	ios_base::sync_with_stdio(0);
	deal();
}