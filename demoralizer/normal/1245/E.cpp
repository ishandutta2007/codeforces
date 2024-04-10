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

const int N=0;

double dp[100];
int g[10][10];
int h[10][10];
pii pos[100];

double get(int i){
	double ans = dp[i];
	int x = pos[i].fr, y = pos[i].sc;
	x -= h[x][y];
	
	amin(ans,dp[g[x][y]]);
	
	return ans;
}

void solve(){
	rep(i,0,10){
		rep(j,0,10){
			cin >> h[i][j];
		}
	}
	
	int x = 9, y = 0;
	
	rep(i,0,100){
		g[x][y] = i;
		pos[i] = {x,y};
		if(x % 2){
			y++;
			if(y == 10){
				y = 9;
				x--;
			}
		}
		else{
			y--;
			if(y < 0){
				y = 0;
				x--;
			}
		}
	}
	
	// rep(i,0,10){
	// 	rep(j,0,10){
	// 		cout << g[i][j] << "\t";
	// 	}
	// 	cout << "\n";
	// }
	
	dp[99] = 0;
	for(int i = 98; i >= 0; i--){
		int cnt = 0;
		dp[i] = 6;
		rep(j,1,7){
			// j = dice outcome
			if(i + j < 100){
				dp[i] += get(i+j);
			}
			else{
				cnt++;
			}
		}
		// (6 - cnt) * dp[i] = sigma(1 + dp[x])
		dp[i] /= (6 - cnt);
	}
	
	cout<<setprecision(10);
	cout<<fixed;
	
	cout << dp[0];
	
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