#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
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

int p[N];

void solve(){
	int n;
	cin >> n;
	oset<int> s;
	rep(i,1,n+1){
		s.insert(i);
	}
	
	rep(i,1,n+1){
		cin >> p[i];
		s.erase(p[i]);
	}
	
	int k = sz(s);
	int ans = k * (k - 1) % M * pw(4) % M;
	
	int tmp = 0;
	rep(i,1,n+1){
		if(p[i] != -1){
			tmp = (tmp + s.ook(p[i])) % M;
		}
		else{
			ans = (ans + tmp * pw(k)) % M;
		}
	}
	
	tmp = 0;
	for(int i = n; i > 0; i--){
		if(p[i] != -1){
			tmp = (tmp + k - s.ook(p[i])) % M;
		}
		else{
			ans = (ans + tmp * pw(k)) % M;
		}
	}
	
	s.clear();
	for(int i = n; i > 0; i--){
		if(p[i] != -1){
			ans = (ans + s.ook(p[i])) % M;
			s.insert(p[i]);
		}
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