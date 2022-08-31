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
const int32_t M=998244353;

const int N=2e5+5;

int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> d(n),pf(n+1);
	rep(i,0,n){
		cin >> d[i];
	}
	sort(all(d));
	rep(i,0,n){
		pf[i+1] = (pf[i] + d[i]) % M;
	}
	
	
	rep(i,0,m){
		int a,b;
		cin >> a >> b;
		int x = lower_bound(all(d),b) - d.begin();
		int cnt = n - x;
		if(a > cnt){
			cout << "0\n";
			continue;
		}
		int small = pf[x];
		int ans = (cnt + 1 - a + M) % M * small % M * pw(cnt + 1) % M;
		// (cnt + 1 - a) / (cnt + 1) * small
		int big = (pf[n] - small + M) % M;
		// (cnt - a) / cnt * big
		ans += (cnt - a + M) % M * big % M * pw(cnt) % M;
		ans %= M;
		cout << ans << "\n";
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