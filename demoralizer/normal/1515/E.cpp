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
const int32_t MM=998244353;

const int N=405;

int32_t mod_inv(int32_t a, int32_t m) {
	int32_t g = m, r = a, x = 0, y = 1;
	while (r != 0) {
		int32_t q = g / r;
		g %= r; swap(g, r);
		x -= q * y; swap(x, y);
	}
	return x < 0 ? x + m : x;
}

int p2[N];
int fact[N];
int invf[N];
int n,M;
int dp[N][N];

int calc(int n,int r){
	if(r == 0){
		return p2[n-1] * invf[n] % M;
	}
	int &ans = dp[n][r];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	rep(left,1,n-1){
		int right = n - 1 - left;
		ans = (ans + calc(right,r-1) * p2[left-1] % M * invf[left]) % M;
	}
	return ans;
}

void solve(){
	cin >> n >> M;
	mem1(dp);
	fact[0] = 1;
	invf[0] = 1;
	p2[0] = 1;
	rep(i,1,n+1){
		fact[i] = fact[i-1] * i % M;
		invf[i] = mod_inv(fact[i],M);
		p2[i] = 2 * p2[i - 1] % M;
	}
	int ans = 0;
	rep(i,0,n+1){
		ans = (ans + fact[n-i] * calc(n,i)) % M;
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