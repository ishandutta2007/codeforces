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

const int N=105;

int d[N];
vector<int> v[N];

void dfs(int z,int par,int dep = 1){
	d[dep]++;
	for(int x:v[z]){
		if(x == par){
			continue;
		}
		dfs(x,z,dep+1);
	}
}

void solve(){
	int n,k;
	cin >> n >> k;
	rep(i,1,n+1){
		v[i].clear();
	}
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	if(k == 2){
		cout << n * (n - 1) / 2 % M << "\n";
		return;
	}
	int ans = 0;
	rep(root,1,n+1){
		vector<vector<int>> deps(n+1);
		for(int x:v[root]){
			mem0(d);
			dfs(x,root);
			rep(z,1,n+1){
				if(d[z]){
					deps[z].pb(d[z]);
				}
			}
		}
		for(vector<int> dep:deps){
			// choose k from dep
			if(sz(dep) < k){
				continue;
			}
			int n = sz(dep);
			vector<vector<int>> dp(n+1,vector<int>(k+1));
			dp[0][0] = 1;
			rep(i,1,n+1){
				rep(j,0,k+1){
					dp[i][j] = dp[i - 1][j];
					if(j){
						dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * dep[i - 1]) % M;
					}
				}
			}
			ans = (ans + dp[n][k]) % M;
		}
	}
	cout << ans << "\n";
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