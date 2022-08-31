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

const int N=0;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,q;
	cin >> n >> q;
	
	vector<int> a(n+1);
	vector<vector<int>> id(n+1);
	rep(i,1,n+1){
		cin >> a[i];
		id[a[i]].pb(i);
	}
	
	while(q--){
		int l,r;
		cin >> l >> r;
		auto dist=uniform_int_distribution<int>(l,r);
		set<int> vals;
		rep(j,0,40){
			int p = dist(rng);
			vals.insert(a[p]);
		}
		
		int mx = 0;
		for(int x:vals){
			int f = upper_bound(all(id[x]),r) - lower_bound(all(id[x]),l);
			amax(mx,f);
		}
		int wid = r - l + 1;
		
		int L = 0, U = mx;
		int ans;
		while(L <= U){
			int m = (L + U) / 2;
			int a = wid - m;
			int b = mx - m;
			int allowed = (a + 1) / 2;
			if(allowed >= b){
				ans = m;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
		ans++;
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