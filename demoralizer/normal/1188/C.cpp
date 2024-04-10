#include "bits/stdc++.h"
using namespace std;
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

const int N=0;

int dp[1005][1005];

void solve(){
	int n,k;
	cin >> n >> k;
	
	vector<int> a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	
	sort(all(a));
	// uniq(a);
	
	// n = sz(a);
	
	int mxb = (100005) / (k - 1) + 20;
	
	vector<int> ans(mxb + 1);
	
	rep(b,1,mxb+1){
		int x = -1;
		rep(i,0,n){
			// dp[i]
			while(a[i] - a[x + 1] >= b){
				x++;
			}
			
			dp[i][0] = 1;
			dp[i][1] = 1;
			rep(j,2,k+1){
				dp[i][j] = 0;
				if(x != -1){
					dp[i][j] = dp[x][j-1];
				}
			}
			if(i){
				rep(j,1,k+1){
					dp[i][j] += dp[i - 1][j];
					if(dp[i][j] >= M) dp[i][j] -= M;
				}
			}
		}
		
		ans[b] = dp[n-1][k];
		if(b > 1){
			ans[b - 1] -= ans[b];
			if(ans[b - 1] < 0) ans[b - 1] += M;
		}
	}
	
	int pr = 0;
	rep(i,1,mxb+1){
		pr = (pr + 1LL * ans[i] * i) % M;
	}
	cout << pr;
	
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