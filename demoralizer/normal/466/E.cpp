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

const int H = 17;
const int N=1e5+5;

vector<pii> v[N];

int par[N][H+1], mx[N][H+1], lvl[N];
void dfs(int z, int p, int w){
	lvl[z] = lvl[p] + 1;
	par[z][0] = p;
	mx[z][0] = w;
	for (int i = 1; i <= H; ++i){
		par[z][i] = par[par[z][i-1]][i-1];
		mx[z][i] = max(mx[z][i-1] , mx[par[z][i-1]][i-1]);
	}
	for(pii x:v[z]){
		if(x.fr==p)continue;
		dfs(x.fr,z,x.sc);
	}
}

pii lca(int x, int y) {
	int val = -1;
	if (lvl[x] < lvl[y]) swap(x, y);
	for (int i = H; i >= 0; i--){
		if (lvl[x] - (1<<i) >= lvl[y]){
			amax(val, mx[x][i]);
			x = par[x][i];
		}
	}
	if (x == y) return {x,val};
	for (int i = H; i >= 0; i--){
		if (par[x][i] != par[y][i]){
			amax(val, mx[x][i]);
			amax(val, mx[y][i]);
			x = par[x][i], y = par[y][i];
		}
	}
	return {par[x][0],val};
}

int boss[N];

vector<int> pack;

vector<pii> q;

void solve(){
	int n,m;
	cin>>n>>m;
	
	int cnt = 0;
	
	rep(i,0,m){
		int t,x;
		cin>>t>>x;
		if(t==1){
			int y;
			cin>>y;
			boss[x] = y;
			v[y].pb({x,cnt});
		}
		else if(t==2){
			cnt++;
			pack.pb(x);
		}
		else{
			int i;
			cin>>i;
			q.pb({x,i});
		}
	}
	
	int root = 0;
	rep(i,1,n+1){
		if(!boss[i]){
			if(!root) root = i;
			else{
				v[root].pb({i,INF});
			}
		}
	}
	
	dfs(root, 0 , 0);
	
	for(auto query:q){
		int x = pack[query.sc-1];
		int y = query.fr;
		pii ans = lca(x,y);
		if(ans.fr == y && ans.sc < query.sc){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
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