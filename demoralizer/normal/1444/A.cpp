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
	int p,q;
	
	
	cin >> p >> q;
	int orp = p;
	
	vector<pii> f;
	int x = q;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){
			int cnt = 0;
			while(x % i == 0){
				cnt++;
				x /= i;
			}
			f.pb({i,cnt});
		}
	}
	if(x != 1){
		f.pb({x,1});
	}
	
	int ans = p;
	
	for(auto x:f){
		int pr = x.fr;
		int freq = x.sc;
		int cnt = 0;
		while(p % pr == 0) p /= pr, cnt++;
		
		int req = max(cnt - freq + 1, 0LL);
		int val = 1;
		rep(i,0,req) val *= pr;
		amin(ans,val);
	}
	cout << orp / ans << "\n";
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