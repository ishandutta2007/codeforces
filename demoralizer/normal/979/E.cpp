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

const int N=55;

int dp[N][N][N][N][2];
int c[N];
int pow2[N];
int n,p;

// at id,(n0 0s and n1 1s on right),(p0,p1 parity changers),(p parity)
int calc(int id,int n0,int n1,int p0,int p1,int p){
	if(n0 < 0 || n1 < 0 || p0 < 0 || p1 < 0 || n0 < p0 || n1 < p1){
		return 0;
	}
	if(id == n){
		if(n0 || n1 || p0 || p1){
			return 0;
		}
		return (p == 0);
	}
	int &ans = dp[n0][n1][p0][p1][p];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	int f0 = 0;
	int f1 = 0;
	
	// non-parity changer = connected to odd num of parity changers
	// parity didn't change = connected to odd num of parity changers
	
	// fill 0
	if(c[id] != 1 && n0){
		// this is a parity changer and parity changed
		if(1){
			f0 = (f0 + calc(id+1,n0-1,n1,p0-1,p1,!p) * pow2[n1-p1 + max(p1-1,0ll)]) % M;
		}
		// this is not a parity changer and parity didn't change
		if(p1 > 0){
			f0 = (f0 + calc(id+1,n0-1,n1,p0,p1,p) * pow2[n1-1]) % M;
		}
		f0 = (f0 * pow2[n0-1]) % M;
	}
	// fill 1
	if(c[id] != 0 && n1){
		// this is a parity changer and parity changed
		if(1){
			f1 = (f1 + calc(id+1,n0,n1-1,p0,p1-1,!p) * pow2[n0-p0 + max(p0-1,0ll)]) % M;
		}
		// this is not a parity changer and parity didn't change
		if(p0 > 0){
			f1 = (f1 + calc(id+1,n0,n1-1,p0,p1,p) * pow2[n0-1]) % M;
		}
		f1 = (f1 * pow2[n1-1]) % M;
	}
	
	ans = (f0 + f1) % M;
	return ans;
}

void solve(){
	mem1(dp);
	pow2[0] = 1;
	rep(i,1,N){
		pow2[i] = 2 * pow2[i - 1] % M;
	}
	cin >> n >> p;
	rep(i,0,n){
		cin >> c[i];
	}
	
	int ans = 0;
	
	rep(i,0,n+1){
		rep(j,0,i+1){
			rep(k,0,n-i+1){
				// cout << i << " " << n - i << " " << j << " " << k << " -> ";
				ans += calc(0,i,n-i,j,k,p);
				// cout << calc(0,i,n-i,j,k,p) << "\n";
			}
		}
	}
	cout << ans % M;
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