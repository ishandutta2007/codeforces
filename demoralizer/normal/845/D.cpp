#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

const long long INF=1e6;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

int t[N],s[N];

int dp[2][305][2]; // pos,lim,overtake
// dp[0][304][1] = 0, dp[0][x][y] = INF;

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> t[i];
		if(t[i] == 1 || t[i] == 3){
			cin >> s[i];
		}
	}
	rep(j,0,305){
		rep(k,0,2){
			dp[0][j][k] = INF;
		}
	}
	int speed = s[0];
	dp[0][304][1] = 0;
	rep(i,1,n){
		
		int z = i % 2;
		// i = z, i - 1 = !z
		if(t[i] == 1){
			speed = s[i];
			rep(j,0,305){
				rep(k,0,2){
					dp[z][j][k] = dp[!z][j][k];
				}
			}
		}
		if(t[i] == 2){
			rep(j,0,305){
				dp[z][j][1] = dp[!z][j][1];
				dp[z][j][0] = INF;
			}
		}
		if(t[i] == 3 || t[i] == 5){
			int nl = s[i];
			if(t[i] == 5) nl = 304;
			rep(k,0,2){
				int nv = INF;
				rep(j,0,305){
					amin(nv,dp[!z][j][k]);
					dp[z][j][k] = dp[!z][j][k] + 1;
				}
				dp[z][nl][k] = nv;
			}
		}
		if(t[i] == 4){
			rep(j,0,305){
				dp[z][j][1] = min(dp[!z][j][0], dp[!z][j][1]);
				dp[z][j][0] = dp[!z][j][0] + 1;
			}
		}
		if(t[i] == 6){
			rep(j,0,305){
				dp[z][j][1] = dp[!z][j][1] + 1;
				dp[z][j][0] = min(dp[!z][j][0], dp[!z][j][1]);
			}
		}
		rep(j,0,305){
			rep(k,0,2){
				if(j < speed) dp[z][j][k] = INF;
			}
		}
	}
	
	int ans = INF;
	rep(j,0,305){
		rep(k,0,2){
			amin(ans,dp[(n-1)%2][j][k]);
		}
	}
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