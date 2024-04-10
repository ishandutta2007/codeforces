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
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=55;

int a[N][N];

int get(int x1, int y1, int x2, int y2){
	x1--;
	y1--;
	return (a[x2][y2] - a[x1][y2] - a[x2][y1] + a[x1][y1]) == 0;
}

int dp[N][N][N][N];

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,n){
			a[i+1][j+1] = (s[j] == '#');
		}
	}
	
	rep(i,1,n+1){
		rep(j,1,n+1){
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	
	rep(wid_x,1,n+1){
		rep(wid_y,1,n+1){
			for(int x1 = 1, x2 = wid_x; x2 <= n; x1++, x2++){
				for(int y1 = 1, y2 = wid_y; y2 <= n; y1++, y2++){
					int ans = max(wid_x,wid_y);
					if(get(x1,y1,x2,y2)) ans = 0;
					
					rep(x3,x1,x2){
						amin(ans,dp[x1][y1][x3][y2] + dp[x3+1][y1][x2][y2]);
					}
					rep(y3,y1,y2){
						amin(ans,dp[x1][y1][x2][y3] + dp[x1][y3+1][x2][y2]);
					}
					
					dp[x1][y1][x2][y2] = ans;
				}
			}
		}
	}
	
	
	cout << dp[1][1][n][n];
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