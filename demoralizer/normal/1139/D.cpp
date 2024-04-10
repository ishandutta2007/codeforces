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

const int N=1e5+5;

int32_t mod_inv(int32_t a, int32_t m = M) {
	int32_t g = m, r = a, x = 0, y = 1;
	while (r != 0) {
		int32_t q = g / r;
		g %= r; swap(g, r);
		x -= q * y; swap(x, y);
	}
	return x < 0 ? x + m : x;
}

int prime[N];
vector<int> fac[N];

int dp[N];

void solve(){
	int m;
	cin >> m;
	rep(i,2,N){
		if(!prime[i]){
			for(int j = i; j < N; j += i){
				fac[j].pb(i);
				prime[j] = 1;
			}
		}
		else{
			prime[i] = 0;
		}
	}
	
	int minv = mod_inv(m);
	
	dp[1] = 0;
	int ans = 0;
	rep(i,2,m+1){
		int p = 1;
		for(int x:fac[i]) p *= x;
		if(p == i){
			int k = sz(fac[i]);
			int div = 1;
			rep(j,0,1<<k){
				int q = 1;
				rep(x,0,k){
					if(j >> x & 1){
						q *= fac[i][x];
					}
				}
				int nums = 0;
				int x = j;
				while(x < (1 << k)){
					int r = 1;
					rep(y,0,k){
						if(x >> y & 1){
							r *= fac[i][y];
						}
					}
					int mult = 1 - ppc(x ^ j) % 2 * 2;
					nums += mult * (m / r);
					x = (x + 1) | j;
				}
				if(p != q){
					dp[i] = (dp[i] + (nums * minv % M) * dp[q]) % M;
				}
				else{
					div = m * mod_inv(m - nums) % M;
				}
			}
			dp[i] = (dp[i] + 1) * div % M;
		}
		dp[i] = dp[p];
		ans = (ans + dp[i]) % M;
	}
	ans = (ans * minv + 1) % M;
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