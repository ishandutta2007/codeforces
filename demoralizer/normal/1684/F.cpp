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



void solve(){
	int n,m;
	cin >> n >> m;
	map<int, vector<int>> ids;
	rep(i,0,n){
		int x;
		cin >> x;
		ids[x].pb(i + 1);
	}
	
	vector<int> vals(n + 1);
	
	rep(i,0,m){
		int l,r;
		cin >> l >> r;
		amax(vals[l],r);
	}
	rep(i,1,n+1){
		amax(vals[i],vals[i-1]);
	}
	
	// true if the segment is problematic
	auto check_in = [&](int l, int r){
		return vals[l] >= r;
	};
	
	int x = INF, y = -INF;
	
	for(auto &v:ids){
		int s = sz(v.sc);
		rep(i,1,s){
			int l = v.sc[i - 1], r = v.sc[i];
			if(check_in(l,r)){
				amin(x, r);
				amax(y, l);
			}
		}
	}
	
	
	vector<pii> conflict;
	
	for(auto &v:ids){
		vector<int> b;
		for(int val:v.sc){
			if(val < x || val > y){
				b.pb(val);
			}
		}
		
		int s = sz(b);
		rep(i,1,s){
			int l = b[i - 1], r = b[i];
			if(check_in(l,r)){
				conflict.pb({l,r});
			}
		}
	}
	
	if(conflict.empty()){
		int ans = y - x + 1;
		amax(ans, 0);
		cout << ans << "\n";
		return;
	}
	
	if(x <= y){
		conflict.pb({x,y});
	}
	sort(all(conflict));
	
	int maxl = -INF, minr = INF;
	if(x <= y){
		maxl = y;
		minr = x;
	}
	for(auto a:conflict){
		amax(maxl, a.fr);
		amin(minr, a.sc);
		// cout << a << "\n";
	}
	int ans = -1;
	if(ans < 0){
		ans = INF;
		int maxr = maxl;
		for(auto a:conflict){
			if(a.fr > minr) break;
			amin(ans, maxr - a.fr + 1);
			amax(maxr, a.sc);
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