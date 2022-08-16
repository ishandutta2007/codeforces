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

const int N=2e3+105;

int n,k;
int dp[N][N];
int a[N];

int calc(int i, int j){
	if(j < 0){
		return -INF;
	}
	if(i == -1){
		if(j == 0) return 0;
		return -INF;
	}
	int &ans = dp[i][j];
	if(ans != -1){
		return ans;
	}
	ans = (j == a[i]) + calc(i - 1, j);
	amax(ans,calc(i - 1, j - 1));
	return ans;
}

void solve(){
	cin >> n >> k;
	rep(i,0,n+10){
		rep(j,0,n+10){
			dp[i][j] = -1;
		}
	}
	rep(i,0,n){
		cin >> a[i];
		a[i] = i - a[i] + 1;
	}
	
	rep(i,0,n+1){
		if(calc(n-1,i) >= k){
			cout << i << "\n";
			return;
		}
	}
	
	cout << -1 << "\n";
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