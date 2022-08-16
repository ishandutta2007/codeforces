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

const long long INF=1e9 + 7;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=5005;

unsigned int t[N];
int x[N];
unsigned 
int dp[N][N][2];

unsigned int myabs(int x){
	return abs(x);
}

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> t[i] >> x[i];
	}
	
	// dp[i][j][0] = at i, clone at j
	// dp[i][j][1] = at j, clone at j, collected i
	
	// dp[i][j][0] -> dp[i-1][j][0] or dp[i-1][j][1]
	// dp[i][j][1] -> dp[i][i][0] or maybe clone to clone (clone rush) -> dp[i-1][i][1] <<---
	// j >= i
	rep(i,0,n+1){
		rep(j,i,n+1){
			dp[i][j][0] = dp[i][j][1] = INF;
		}
	}
	
	rep(i,0,n+1){
		rep(j,i,n+1){
			if(i == j && i == 0){
				dp[i][j][0] = 0;
				continue;
			}
			
			if(i != j){
				amin(dp[i][j][1],dp[i][i][0] + myabs(x[j] - x[i]));
				if(i){
					if(dp[i-1][i][1] <= t[i]){
						amin(dp[i][j][1], max(dp[i-1][i][1] + myabs(x[j] - x[i]), t[i]));
					}
					amin(dp[i][j][1], max(dp[i-1][i][0] + myabs(x[j] - x[i-1]), t[i]));
				}
			}
			
			
			if(i){
				amin(dp[i][j][0], dp[i-1][j][0] + myabs(x[i] - x[i-1]));
				amin(dp[i][j][0], dp[i-1][j][1] + myabs(x[i] - x[j]));
			}
			
			amax(dp[i][j][0], t[i]);
			if(dp[i][j][0] > t[i]) dp[i][j][0] = INF;
			if((i == n && dp[i][j][0] == t[i]) || (i == n-1 && j == n && dp[i][j][0] <= t[i])){
				cout << "YES";
				return;
			}
			
		}
	}
	cout << "NO";
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