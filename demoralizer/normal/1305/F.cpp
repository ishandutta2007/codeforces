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
vector<int> pf;
void dofor(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			while(n % i == 0) n /= i;
			pf.pb(i);
		}
	}
	if(n != 1){
		pf.pb(n);
	}
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto dist=uniform_int_distribution<int>(0,n-1);
	
	rep(i,0,20){
		int x = a[dist(rng)];
		rep(y,max(2LL,x-2),x+3){
			dofor(y);
		}
	}
	
	sort(all(pf));
	uniq(pf);
	
	int ans = n;
	for(int x:pf){
		int tot = 0;
		rep(i,0,n){
			int tmp = a[i] % x;
			int y = x - tmp;
			if(a[i] != tmp) amin(y,tmp);
			tot += y;
		}
		amin(ans, tot);
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