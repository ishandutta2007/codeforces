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

const int N=3e5+5;

int32_t mod_inv(int32_t a, int32_t m = M) {
	int32_t g = m, r = a, x = 0, y = 1;
	while (r != 0) {
		int32_t q = g / r;
		g %= r; swap(g, r);
		x -= q * y; swap(x, y);
	}
	return x < 0 ? x + m : x;
}

vector<int> v[N];
int dp[N][3];
// 0 -> singleton
// 1 -> unmatched
// 2 -> matched

void dfs(int z,int p = 0){
	dp[z][0] = 1;
	dp[z][1] = 1;
	dp[z][2] = 0;
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		dfs(x,z);
		dp[z][0] = dp[z][0] * (dp[x][0] + dp[x][2]) % M;
		dp[z][1] = dp[z][1] * (dp[x][0] + 2 * dp[x][2]) % M;
		dp[z][2] = (dp[z][2] + dp[x][1] * mod_inv((dp[x][0] + 2 * dp[x][2]) % M)) % M;
	}
	dp[z][2] = dp[z][2] * dp[z][1] % M;
}

void solve(){
	int n;
	cin >> n;
	rep(i,0,n-1){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	int ans = (dp[1][0] + dp[1][2]) % M;
	cout << ans;
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