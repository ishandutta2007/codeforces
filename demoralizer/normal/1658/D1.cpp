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
	int l,r;
	cin >> l >> r;
	vector<int> a(r - l + 1);
	for(int &x:a){
		cin >> x;
	}
	
	vector<int> oa = a;
	
	int ans = 0;
	int x = 0;
	int y = l;
	rep(z,0,2){
		for(int b = 16; b >= 0; b--){
			int bit = y >> b & 1;
			int cnt = 0;
			rep(i,l,r+1){
				if((i >> b) == (y >> b)) cnt++;
			}
			int c[2] = {0,0};
			for(int x:a){
				c[x >> b & 1]++;
			}
			int val = 0;
			if(c[bit] != cnt) val = 1;
			assert(c[bit^val] == cnt);
			
			x |= (val << b);
			
			bit ^= val;
			vector<int> tmp;
			for(int x:a){
				if((x >> b & 1) == bit) tmp.pb(x);
			}
			a = tmp;
		}
		a = oa;
		vector<int> tmp;
		for(int b:a){
			tmp.pb(b ^ x);
		}
		
		bool ok = 1;
		sort(all(tmp));
		rep(i,l,r+1){
			if(tmp[i - l] != i) ok = 0;
		}
		if(ok){
			ans = x;
		}
		
		y = r;
	}
	
	cout << x << "\n";
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