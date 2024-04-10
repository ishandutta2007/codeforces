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
	// we can make 2^(n - 1) almost sorted perms with n elements
	set<int> elements;
	int n;
	int k;
	cin >> n >> k;
	rep(i,1,n+1){
		elements.insert(i);
	}
	
	vector<int> ans;
	
	// rep(i,1,n+1){
	// 	int rem = sz(elements) - 2;
	// 	// 2 ^ rem perms
	// 	if(rem > 60 || ){
	// 		// put smallest only
	// 	}
	// }
	
	if(n < 61 && (1ll << (n - 1)) < k){
		cout << -1 << "\n";
		return;
	} 
	
	while(sz(elements) - 1 > 0){
		int rem = sz(elements) - 2;
		if(rem > 60){
			// put smallest
			int e = *elements.begin();
			ans.pb(e);
			elements.erase(e);
			continue;
		}
		int val = 1ll << rem;
		// if i put smallest here, val can be formed
		if(val >= k){
			// put smallest
			int e = *elements.begin();
			ans.pb(e);
			elements.erase(e);
			continue;
		}
		vector<int> buff;
		while(val < k){
			int e = *elements.begin();
			elements.erase(e);
			buff.pb(e);
			k -= val;
			rem = sz(elements) - 2;
			val = 1ll << rem;
		}
		if(sz(elements)){
			int e = *elements.begin();
			buff.pb(e);
			elements.erase(e);
		}
		reverse(all(buff));
		for(int x:buff){
			ans.pb(x);
		}
	}
	if(sz(elements)){
		ans.pb(*elements.begin());
	}
	for(int x:ans){
		cout << x << " ";
	}
	cout << "\n";
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