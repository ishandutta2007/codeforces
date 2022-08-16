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
const int H = 17;

vector<int> v[N];
int par[N][H+1], lvl[N] , sz[N];
void dfs(int z, int p){
	lvl[z] = lvl[p] + 1;
	sz[z] = 1;
	par[z][0] = p;
	for (int i = 1; i <= H; ++i){
		par[z][i] = par[par[z][i-1]][i-1];
	}
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
		sz[z] += sz[x];
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

int ances(int z, int l){
	int dis = lvl[z] - l;
	for (int i = H; i >= 0; i--){
		if(dis >= (1<<i)){
			dis -= (1<<i);
			z = par[z][i];
		}
	}
	return z;
}

void solve(){
	int n;
	cin>>n;
	rep(i,0,n-1){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(1,0);
	int m;
	cin>>m;
	rep(z,0,m){
		int x,y;
		cin>>x>>y;
		int ans;
		int l = lca(x,y);
		if(x == y){
			ans = n;
		}
		else if(lvl[x] == lvl[y]){
			int lev = lvl[l] + 1;
			ans = n - sz[ances(x,lev)] - sz[ances(y,lev)];
		}
		else{
			int dis = lvl[x] + lvl[y] - 2 * lvl[l];
			if(dis % 2) ans = 0;
			else{
				dis /= 2;
				if(lvl[x] < lvl[y]) swap(x,y);
				int k = ances(x,lvl[x] - dis);
				int d = ances(x,lvl[x] - dis + 1);
				ans = sz[k] - sz[d];
			}
		}
		cout<<ans<<"\n";
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