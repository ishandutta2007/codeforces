#include <bits/stdc++.h>
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

int a[N], n, k, l, e;

int dp[5005][5005]; // dp[x][y] = we did x blocks and y of them were of length (l+1)

void solve(){
	n,k;
	cin>>n>>k;
	rep(i,0,n){
		cin>>a[i+1];
	}
	sort(a+1,a+n+1);
	l = n/k;
	e = n%k;
	rep(j,1,e+1)dp[0][j]=INF;
	rep(i,1,k+1){
		dp[i][0] = dp[i-1][0] + a[l*i] - a[l*(i-1) + 1];
		rep(j,1,e+1){
			dp[i][j] = min(dp[i-1][j] + a[l*i + j] - a[l*(i-1) + 1 + j],dp[i-1][j-1] + a[l*i + j] - a[l*(i-1) + j]);
		}
	}
	cout<<dp[k][e];
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