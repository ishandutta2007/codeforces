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

const int N=3e5+5;

vector<int> v[N];

const int H = 18;
int par[N][H+1], lvl[N];
void dfs(int z, int p = 0){
	lvl[z] = lvl[p] + 1;
	par[z][0] = p;
	for (int i = 1; i <= H; ++i){
		par[z][i] = par[par[z][i-1]][i-1];
	}
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
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

int lvl_ancestor(int x,int d){
	assert(lvl[x] >= d);
	if(lvl[x] == d) return x;
	int diff = lvl[x] - d;
	for (int i = H; i >= 0; i--){
		if(diff >> i & 1){
			x = par[x][i];
		}
	}
	return x;
}

int lc[N]; // lca count
int sv[N]; // sec ver

int abc[N];
int cde[N];
int efg[N];


void add_chain(int a,int x){
	sv[a]++;
	abc[x]++;
	// cde[a]++;
}

int dfs2(int z,int p = 0){
	int val = abc[z];
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		val += dfs2(x,z);
	}
	cde[z] = val;
	val -= sv[z];
	efg[z] = val;
	return val;
}

map<pii, int> mp[N];

void solve(){
	int n;
	cin >> n;
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(1);
	
	int m;
	cin >> m;
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		if(x == y){
			// only lca
			lc[x]++;
			continue;
		}
		if(lvl[x] > lvl[y]) swap(x,y);
		
		int k = lca(x,y);
		lc[k]++;
		if(k == x){
			// only chain
			int b = lvl_ancestor(y,lvl[k]+1);
			// {b,y}
			add_chain(b,y);
		}
		else{
			int a = lvl_ancestor(x,lvl[k]+1);
			int b = lvl_ancestor(y,lvl[k]+1);
			// {a,x}
			// {b,y}
			add_chain(a,x);
			add_chain(b,y);
			
			if(a > b) swap(a,b);
			mp[k][{a,b}]++;
			
		}
		
	}
	
	dfs2(1,0);
	int ans = 0;
	rep(i,1,n+1){
		// cout << lc[i] << " " << sv[i] << " " << cde[i] << " " << efg[i] << "\n";
		ans += lc[i] * cde[i];
		ans -= sv[i] * efg[i];
		
		ans += lc[i] * (lc[i] - 1) / 2;
		for(auto &x:mp[i]){
			ans += x.sc * (x.sc - 1) / 2;
		}
		ans -= sv[i] * (sv[i] - 1) / 2;
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