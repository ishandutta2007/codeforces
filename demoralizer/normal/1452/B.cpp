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


 // k = sum / (n - 1)
 // sum divisible by (n-1)
 // for each i a[i] <= sum/(n-1)

void solve(){
	int n;
	cin >> n;
	int sum = 0;
	vector<int> a(n);
	rep(i,0,n){
		cin >> a[i];
		sum += a[i];
	}
	
	int L = 0, U = 1e10;
	int k;
	while(L <= U){
		int m = (L + U) / 2;
		if(m * (n - 1) < sum){
			L = m+1;
			continue;
		}
		int inc = m * (n-1) - sum;
		bool bad = 0;
		for(int x:a){
			if(x > m) bad = 1;
			inc -= (m - x);
		}
		if(inc <= 0 && !bad){
			k = m;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
	}
	
	int ans = (n-1) * k - sum;
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