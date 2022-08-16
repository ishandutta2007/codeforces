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

const int N=1e5+5;

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

vector<int> v[N];
int ans[N];
int dp[N][2];
int mod;

void dfs(int z,int p = 0){
	int ways = 1;
	int cnt = 0;
	for(int x:v[z]){
		if(x == p) continue;
		dfs(x,z);
		int f = 0;
		if(dp[x][f] == 0) f++;
		ways &= dp[x][f];
		cnt += (1-f);
	}
	dp[z][0] = dp[z][1] = 0;
	if(cnt % mod == 0){
		dp[z][0] = ways;
	}
	if((cnt + 1) % mod == 0){
		dp[z][1] = ways;
	}
	// cout << z << " : " << dp[z][0] << " " << dp[z][1] << " " << cnt << "\n";
}

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		v[i].clear();
		ans[i] = 0;
	}
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	ans[1] = pw(2,n-1);
	ans[n] = 0;
	rep(i,2,n){
		mod = i;
		if((n-1) % mod){
			ans[i] = 0;
			continue;
		}
		// cout << "MOD: " << mod << "\n";
		dfs(1,0);
		ans[i] = dp[1][0];
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = 2 * i; j <= n; j += i){
			ans[i] = (ans[i] - ans[j] + M) % M;
		}
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