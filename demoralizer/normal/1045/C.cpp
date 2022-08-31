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

vector<int> g[N];
set<int> v[N];

int p,q;
const int H = 17;
int par[N][H+1], lvl[N];
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
	p = x;
	q = y;
	return par[x][0];
}

int dis(int x,int y){
	p = q = 0;
	int l = lca(x,y);
	int ans = lvl[x] + lvl[y] - 2 * lvl[l];
	if(p && v[p].count(q)){
		ans -= 1;
	}
	// cout << x << " " << y << " " << l << " \n";
	return ans;
}

void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
		v[x].insert(y);
		v[y].insert(x);
	}
	
	queue<int> que;
	lvl[1] = 1;
	que.push(1);
	
	while(!que.empty()){
		int z = que.front();
		que.pop();
		for(int x:g[z]){
			if(lvl[x]) continue;
			lvl[x] = lvl[z] + 1;
			que.push(x);
			par[x][0] = z;
			for (int i = 1; i <= H; ++i){
				par[x][i] = par[par[x][i-1]][i-1];
			}
		}
	}
	
	rep(i,0,q){
		int x,y;
		cin >> x >> y;
		cout << dis(x,y) << "\n";
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