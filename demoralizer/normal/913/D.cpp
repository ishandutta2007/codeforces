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

const int N=2e5+5;

int a[N], t[N];

void solve(){
	int n,T;
	cin>>n>>T;
	rep(i,0,n){
		cin>>a[i]>>t[i];
	}
	int ans;
	int L = 0, U = n;
	while(L <= U){
		int m = (L+U)/2;
		vector<int> v;
		rep(i,0,n){
			if(a[i] >= m) v.pb(t[i]);
		}
		sort(all(v));
		bool f = 1;
		if(sz(v) < m) f = 0;
		else{
			int s = 0;
			rep(i,0,m) s += v[i];
			if(s > T) f = 0;
		}
		if(f){
			ans = m;
			L = m+1;
		}
		else{
			U = m-1;
		}
	}
	cout << ans << "\n" << ans << "\n";
	vector<pii> v;
	rep(i,0,n){
		if(a[i] >= ans) v.pb({t[i],i+1});
	}
	sort(all(v));
	rep(i,0,ans){
		cout << v[i].sc << " ";
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