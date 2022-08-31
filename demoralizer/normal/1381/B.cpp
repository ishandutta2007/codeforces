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

const int N=4005;

int p[N];

int dp[N][N];

void solve(){
	int n;
	cin>>n;
	
	rep(i,0,2*n){
		cin>>p[i];
	}
	
	vector<int> v;
	
	int cnt = 1;
	int boss = p[0];
	rep(i,1,2*n){
		if(p[i] < boss) cnt++;
		else{
			v.pb(cnt);
			cnt = 1;
			boss = p[i];
		}
	}
	
	v.pb(cnt);
	rep(i,0,n+1){
		dp[0][i] = 0;
	}
	
	dp[0][0] = 1;
	dp[0][v[0]] = 1;
	
	// cout<<"------\n";
	// for(int x:v){
	// 	cout<<x<<" ";
	// }
	
	
	rep(i,1,sz(v)){
		dp[i][0] = 1;
		rep(j,1,n+1){
			dp[i][j] = 0;
			dp[i][j] = dp[i-1][j];
			if(j >= v[i]){
				dp[i][j] |= dp[i-1][j-v[i]];
			}
		}
	}
	
	if(dp[sz(v)-1][n] == 1){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	
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