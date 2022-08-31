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
	int n,k,m;
	cin >> n >> k >> m;
	vector<pii> v;
	rep(i,0,n){
		int x;
		cin >> x;
		if(v.empty() || x != v.back().sc){
			v.pb({1,x});
		}
		else{
			v.back().fr++;
		}
		if(v.back().fr == k) v.ppb();
	}
	if(m < 3){
		vector<pii> z;
		rep(i,0,m){
			for(auto x:v){
				z.pb(x);
			}
		}
		vector<pii> p;
		for(auto x:z){
			if(p.empty() || p.back().sc != x.sc){
				p.pb(x);
			}
			else{
				x.fr += p.back().fr;
				p.ppb();
				if(x.fr >= k) x.fr -= k;
				if(x.fr){
					p.pb(x);
				}
			}
		}
		int ans = 0;
		for(auto x:p)
			ans += x.fr;
		cout << ans;
		return;
	}
	
	int ans = 0;
	for(auto x:v)
		ans += x.fr;
	ans *= 2;
	
	deque<pii> mid(all(v));
	while(sz(mid) > 1 && mid.front().sc == mid.back().sc && mid.front().fr + mid.back().fr >= k){
		int val = mid.front().sc;
		int tmp = mid.front().fr + mid.back().fr;
		ans -= k;
		mid.ppf();
		mid.ppb();
		tmp -= k;
		if(tmp){
			mid.pb({tmp,val});
		}
	}
	
	
	if(sz(mid) == 1){
		int tmp = m * mid.front().fr;
		ans -= 2 * mid.front().fr;
		tmp %= k;
		if(tmp == 0){
			cout << 0;
		}
		else{
			cout << ans + tmp;
		}
		return;
	}
	
	if(sz(mid) == 0){
		cout << 0;
		return;
	}
	
	int tmp = 0;
	for(auto x:mid)
		tmp += x.fr;
	cout << ans + tmp * (m - 2);
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