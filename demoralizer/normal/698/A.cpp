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

const long long INF=1e5;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=105;

// dp[i][x] = i-th day, last day xth activity - 0 gym, 1 contest, 2 rest
int dp[N][3];
int a[N];

void solve(){
	int n;
	cin >> n;
	
	rep(i,0,n){
		cin >> a[i];
	}
	
	dp[0][2] = 1;
	dp[0][0] = dp[0][1] = INF;
	if(a[0] % 2) dp[0][1] = 0;
	if(a[0] / 2) dp[0][0] = 0;
	
	rep(i,1,n){
		// dp[i]
		dp[i][2] = 1 + min({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
		if(a[i] % 2){
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
		}
		else{
			dp[i][1] = INF; // no contest
		}
		
		if(a[i] / 2){
			dp[i][0] = min(dp[i-1][1],dp[i-1][2]);
		}
		else{
			dp[i][0] = INF;
		}
		
	}
	cout << min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
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