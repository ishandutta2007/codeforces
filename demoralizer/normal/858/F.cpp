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

// Greedy Edge to Edge matching
int vis[N];
int lev[N];
vector<int> v[N];
vector<pair<int, pii>> ans;

int dfs(int z,int p = 0,int l = 0){
	lev[z] = l;
	vis[z] = 1;
	vector<int> children;
	for(int x:v[z]){
		if(vis[x]){
			if(lev[x] > l){
				children.pb(x);
			}
			continue;
		}
		if(dfs(x,z,l+1)){
			children.pb(x);
		}
	}
	while(sz(children) > 1){
		int x = children.back();
		children.ppb();
		int y = children.back();
		children.ppb();
		ans.pb({x,{z,y}});
	}
	if(sz(children)){
		int c = children.back();
		if(p){
			ans.pb({c,{z,p}});
		}
		return 0;
	}
	return 1;
}

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rep(i,1,n+1){
		if(!vis[i]) dfs(i);
	}
	cout << sz(ans) << "\n";
	for(auto x:ans){
		cout << x << "\n";
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