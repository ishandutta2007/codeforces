#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

const int N=5e5+5;

int n,m,k;
int c[N],boss[N];
vector<int> gp[N],v[N];
bool bpt[N],vis[N],parity[N];

bool dfs(int z,int g,int b){
	vis[z] = 1;
	boss[z] = b;
	for(int x:v[z]){
		if(c[x] != g) continue;
		if(vis[x]){
			if(parity[x] == parity[z]) return 1;
			continue;
		}
		parity[x] = !parity[z];
		if(dfs(x,g,b)) return 1;
	}
	return 0;
}

bool check_bipartite(int g){
	for(int x:gp[g]){
		if(vis[x]) continue;
		if(dfs(x,g,x)) return 0;
	}
	return 1;
}


pii edgs[N];

map<pii, vector<pii>> adj[N][2];
map<pii, vector<pii>> conn;





set<pii> marked;
map<pii, int> mpar; // dumble parity


bool dfs2(pii z,pii gps){
	marked.insert(z);
		
	if(!marked.count({z.fr,!z.sc})){
		mpar[{z.fr,!z.sc}] = !mpar[z];
		if(dfs2({z.fr,!z.sc},gps)) return 1;
	}
	else{
		if(mpar[z] == mpar[{z.fr,!z.sc}]) return 1;
	}
	
	for(pii x:adj[z.fr][z.sc][gps]){
		if(marked.count(x)){
			if(mpar[x] == mpar[z]) return 1;
			continue;
		}
		mpar[x] = !mpar[z];
		if(dfs2(x,gps)) return 1;
	}
	return 0;
}


void solve(){
	cin >> n >> m >> k;
	rep(i,1,n+1){
		cin >> c[i];
		gp[c[i]].pb(i);
	}
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
		edgs[i] = {x,y};
	}
	
	long long total = 0;
	
	rep(i,1,k+1){
		bpt[i] = check_bipartite(i);
		if(bpt[i]) total++;
		// cout << i << " " << bpt[i] << "\n";
	}
	
	rep(i,0,m){
		int x = edgs[i].fr;
		int y = edgs[i].sc;
		if(c[x] == c[y] || !bpt[c[x]] || !bpt[c[y]]) continue;
		// diff groups, both bipartite
		int px = parity[x];
		int py = parity[y];
		x = boss[x];
		y = boss[y];
		if(x > y) swap(x,y),swap(px,py);
		int g1 = c[x], g2 = c[y];
		if(g1 > g2) swap(g1,g2);
		
		adj[x][px][{g1,g2}].pb({y,py});
		adj[y][py][{g1,g2}].pb({x,px});
		
		conn[{g1,g2}].pb({x,px});
		conn[{g1,g2}].pb({y,py});
	}
	
	int invalid = 0;
	
	for(auto &x:conn){
		int g1 = x.fr.fr;
		int g2 = x.fr.sc;
		vector<pii> &vers = x.sc;
		
		marked.clear();
		mpar.clear();
		
		for(auto y:vers){
			if(marked.count(y)) continue;
			if(dfs2(y,x.fr)){
				invalid++;
				break;
			}
		}
		
	}
	
	cout << total * (total - 1) / 2 - invalid;
	
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