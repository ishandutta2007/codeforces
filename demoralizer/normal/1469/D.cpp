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
	int n;
	cin >> n;
	
	if(n == 3){
		cout << "2\n3 2\n3 2\n";
		return;
	}
	if(n == 4){
		cout << "3\n3 4\n4 2\n4 2\n";
		return;
	}
	
	// 1, 2, 4, 8
	if(n < 9){
		// n > 4
		vector<pii> moves;
		moves.pb({3,n});
		// 1
		rep(i,5,n){
			moves.pb({i,n});
		}
		// n - 1 - 4 + 1 = n - 4
		// 2,4,n
		
		moves.pb({n,4});
		moves.pb({n,4});
		// n - 2 moves
		
		// 2,4
		moves.pb({4,2});
		moves.pb({4,2});
		// n moves
		
		assert(sz(moves) == n);
		cout << n << "\n";
		for(auto x:moves){
			cout << x << "\n";
		}
		
		return;
	}
	
	vector<pii> moves;
	rep(i,3,n){
		if(i == 4 || i == 8) continue;
		moves.pb({i,n});
	}
	// n - 1 - 4 = n - 5
	
	rep(i,0,6){
		moves.pb({n,8});
	}
	
	// n + 1 moves
	
	// 2,4,8
	
	moves.pb({8,4});
	moves.pb({8,4});
	
	// n + 3 moves
	
	// 2,4
	moves.pb({4,2});
	moves.pb({4,2});
	
	// 1,1,1,1,1,2 and n + 5 moves
	
	assert(sz(moves) == n + 5);
	cout << n + 5 << "\n";
	for(auto x:moves){
		cout << x << "\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}