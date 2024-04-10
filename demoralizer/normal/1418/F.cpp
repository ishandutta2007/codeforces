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

const int N=2e5+5;
#define SIEVE
vector<int> f[N];
void sieve(){
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i){
			f[j].pb(i);
		}
	}
}

using ll = long long;

void solve(){
	int n,m;
	ll l,r;
	cin >> n >> m >> l >> r;
	set<pii> s;
	int u = m;
	int v = m;
	rep(x1,1,n+1){
		while(1LL * x1 * u >= l){
			for(int fac:f[u]){
				s.insert({fac,u});
			}
			u--;
		}
		while(1LL * x1 * v > r){
			for(int fac:f[v]){
				s.erase({fac,v});
			}
			v--;
		}
		
		// cout << x1 << " -> " << u << " " << v << "\n";
		
		bool found = 0;
		for(int z:f[x1]){
			auto it = s.upper_bound({z,m+10});
			if(it == s.end()){
				break;
			}
			ll x2 = (1LL * x1 * ll(it->fr)) / z;
			assert(x2 > 0);
			if(x2 <= n){
				int y1 = it->sc;
				int y2 = 1LL * y1 * z / (it->fr);
				// assert(1LL * x1 * y1 == 1LL * x2 * y2);
				cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
				found = 1;
				break;
			}
		}
		if(!found){
			cout << "-1\n";
		}
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