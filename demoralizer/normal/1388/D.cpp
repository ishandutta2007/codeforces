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

int a[N],b[N];
int dp[N];
int ans = 0;

vector<int> v[N];
// vector<int> vr[N];
int vis[N];
void dfs(int z){
	vis[z]=1;
	dp[z] = a[z];
	for(int x:v[z]){
		if(!vis[x])
			dfs(x);
		if(dp[x] > 0){
			dp[z] += dp[x];
		}
	}
	if(z)ans += dp[z];
}

vector<int> order;
queue<int> q;

void dfs2(int z){
	vis[z] = 1;
	for(int x:v[z]){
		if(dp[x] > 0){
			dfs2(x);
		}
		else{
			q.push(x);
		}
	}
	if(z) order.pb(z);
}

void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
	}
	rep(i,1,n+1){
		cin>>b[i];
		if(b[i] == -1) b[i] = 0;
		v[b[i]].pb(i);
		// vr[i].pb(b[i]);
	}
	
	dfs(0);
	mem0(vis);
	cout<<ans<<"\n";
	q.push(0);
	while(!q.empty()){
		int z = q.front();
		q.pop();
		dfs2(z);
	}
	for(int x:order){
		cout<<x<<" ";
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