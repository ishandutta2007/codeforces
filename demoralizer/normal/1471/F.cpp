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
int vis[N],teach[N];

int dfs_conn(int z){
	vis[z] = 1;
	int ret = 1;
	for(int x:v[z]){
		if(vis[x]) continue;
		ret += dfs_conn(x);
	}
	return ret;
}

void dfs(int z){
	if(teach[z]){
		vis[z] = 1;
		vector<int> studs;
		for(int x:v[z]){
			if(vis[x] || !teach[x]) continue;
			studs.pb(x);
			teach[x] = 0;
		}
		for(int x:studs){
			dfs(x);
		}
	}
	else{
		vis[z] = 1;
		for(int x:v[z]){
			if(vis[x] || !teach[x]) continue;
			dfs(x);
		}
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,n+1){
		v[i].clear();
		vis[i] = 0;
		teach[i] = 1;
	}
	
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	if(dfs_conn(1) != n){
		cout << "NO\n";
		return;
	}
	
	rep(i,1,n+1){
		vis[i] = 0;
	}
	
	dfs(1);
	cout << "YES\n";
	int cnt = 0;
	rep(i,1,n+1){
		if(teach[i]) cnt++;
	}
	cout << cnt << "\n";
	rep(i,1,n+1){
		if(teach[i]) cout << i << " ";
	}
	cout << "\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}