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

const int N=5005;

int n,k,q;
int dp[N][N];
int coeff[N];

int calc(int id,int rem){
	if(id < 0 || id >= n){
		return 0;
	}
	if(rem == 0){
		return 1;
	}
	int &ans = dp[id][rem];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	ans = (calc(id+1,rem-1) + calc(id-1,rem-1)) % M;
	return ans;
}

void solve(){
	mem1(dp);
	cin >> n >> k >> q;
	
	vector<int> a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	
	int ans = 0;
	rep(i,0,n){
		rep(j,0,k+1){
			coeff[i] = (coeff[i] + calc(i,j) * 1ll * calc(i,k-j) % M) % M;
		}
		ans = (ans + coeff[i] * 1ll * a[i] % M) % M;
		// cout << coeff[i] << " ";
	}
	// cout << "\n";
	
	rep(zz,0,q){
		int i,x;
		cin >> i >> x;
		i--;
		
		// ans = ans - coeff[i] * a[i] + coeff[i] * x;
		int diff = (x - a[i] + M) % M;
		ans = (ans + coeff[i] * 1ll * diff) % M;
		cout << ans << "\n";
		a[i] = x;
	}
	
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