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

const int N=505;

int colsum[N];

int dp[N][N];

void solve(){
	int n,m,mod;
	cin>>n>>m>>mod;
	
	rep(i,0,m){
		string s;
		cin>>s;
		int rowsum = 0;
		rep(j,0,n){
			rowsum += (s[j] == '1');
			colsum[j] += (s[j] == '1');
		}
		if(rowsum != 2){
			cout << 0;
			return;
		}
	}
	
	int cnt1 = 0, cnt2 = 0;
	rep(j,0,n){
		if(colsum[j] == 1) cnt1++;
		if(colsum[j] == 0) cnt2++;
		if(colsum[j] > 2){
			cout<<0;
			return;
		}
	}
	
	if(cnt1 + 2 * cnt2 != (n-m) * 2){
		cout<<0;
		return;
	}
	
	// answer = dp[cnt1][cnt2]
	
	dp[0][0] = 1;
		rep(y,0,cnt2+1){
	rep(x,0,501){
			if(x >= 2) dp[x][y] = (dp[x][y] + dp[x-2][y] * (x*(x-1)/2 % mod)) % mod;
			if(y >= 2) dp[x][y] = (dp[x][y] + dp[x+2][y-2] * (y*(y-1)/2 % mod)) % mod;
			if(x >= 1 && y >= 1) dp[x][y] = (dp[x][y] + dp[x][y-1] * (x * y % mod)) % mod;
		}
	}
	
	cout << dp[cnt1][cnt2];
	
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