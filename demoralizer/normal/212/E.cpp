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

const int N=5005;

int n;
int avail[N]; // avail[x] = 1 if a = x is possible
int dp[N];

vector<int> v[N];

int dfs(int z,int p,int root){
	int ret = 1;
	for(int x:v[z]){
		if(x==p)continue;
		if(z != root)
			ret += dfs(x,z,root);
		else{
			int tmp = dfs(x,z,root);
			for(int i = n; i >= tmp; i--){
				dp[i] |= dp[i - tmp];
			}
		}
	}
	return ret;
}

void solve(){
	cin >> n;
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	rep(i,1,n+1){
		dp[0] = 1;
		dfs(i,0,i);
		for(int i = 1; i < n; i++){
			avail[i] |= dp[i];
			dp[i] = 0;
		}
	}
	
	// avail[i] = 1 for all valid a = i
	vector<pii> pr;
	for(int i = 1; i < n - 1; i++){
		if(avail[i]){
			pr.pb({i,n-1-i});
		}
	}
	sort(all(pr));
	cout << sz(pr) << "\n";
	for(auto x:pr){
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