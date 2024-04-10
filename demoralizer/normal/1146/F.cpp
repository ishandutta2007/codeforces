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
const int32_t M=998244353;

const int N=2e5+5;

int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

vector<vector<int>> v;
int dp[N][3];

void dfs(int z){
	dp[z][0] = 1;
	dp[z][1] = 1;
	dp[z][2] = 0;
	for(int x:v[z]){
		dfs(x);
		dp[z][0] = dp[z][0] * dp[x][2] % M;
		dp[z][1] = dp[z][1] * (dp[x][1] * pw(dp[x][2]) % M + 1) % M;
		dp[z][2] = (dp[z][2] + dp[x][1] * pw(dp[x][2])) % M;
	}
	
	dp[z][1] = (dp[z][1] + M - 1) * dp[z][0] % M;
	
	dp[z][2] = dp[z][2] * dp[z][0] % M;
	dp[z][2] = (dp[z][1] + dp[z][0] - dp[z][2] + M) % M;
	
	if(v[z].empty()){
		dp[z][0] = 0;
		dp[z][1] = 1;
		dp[z][2] = 1;
	}
}

void solve(){
	int n;
	cin >> n;
	v.resize(n + 1);
	rep(i,2,n+1){
		int x;
		cin >> x;
		v[x].pb(i);
	}
	dfs(1);
	cout << dp[1][2];
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