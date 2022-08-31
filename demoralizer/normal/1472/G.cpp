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

vector<int> v[N];
int d[N];
int vis[N];
int ans[N];

void dfs(int z){
	vis[z] = 1;
	for(int x:v[z]){
		if(d[x] <= d[z]){
			continue;
		}
		if(!vis[x]) dfs(x);
		ans[z] = min(ans[z], ans[x]);
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,1,n+1){
		v[i].clear();
		vis[i] = 0;
		d[i] = INF;
	}
	
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
	}
	
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	d[1] = 0;
	// BFS or Breadth First Search
	while(!q.empty()){
		int z = q.front();
		q.pop();
		for(int x:v[z]){
			if(vis[x]) continue;
			vis[x] = 1;
			d[x] = d[z] + 1;
			q.push(x);
		}
	}
	
	rep(i,1,n+1){
		vis[i] = 0;
		ans[i] = d[i];
		for(int x:v[i]){
			ans[i] = min(ans[i], d[x]);
		}
	}
	
	rep(i,1,n+1){
		if(vis[i]) continue;
		dfs(i);
	}
	
	rep(i,1,n+1){
		cout << ans[i] << " ";
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