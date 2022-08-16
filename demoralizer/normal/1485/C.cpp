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
	int x,y;
	cin >> x >> y;
	
	int mxb = 0;
	int ans = 0;
	for(int b = 1; (b - 1) * (b + 1) <= 2 * x && b <= y; b++){ // z >= b - 1
		ans += min(x / (b + 1), b - 1);
		mxb = b;
	}
	for(int z = 1; z * z < x; z++){ // z < b - 1
		int L = mxb+1, U = y;
		int sm = -1;
		while(L <= U){
			int m = (L + U) / 2;
			if(x / (m + 1) <= z){
				sm = m;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
		
		int bg = -1;
		L = mxb+1, U = y;
		while(L <= U){
			int m = (L + U) / 2;
			if(x / (m + 1) >= z){
				bg = m;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
		
		if(sm == -1 || bg == -1) continue;
		
		int poss = (bg - sm + 1);
		assert(z < sm - 1);
		ans += poss * z;
		
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