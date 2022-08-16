#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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
	int k,n;
	cin>>k>>n;
	
	map<string, vector<int>> palin,non;
	
	rep(i,0,k){
		string s;int cost;
		cin>>s>>cost;
		string r;
		r = s;
		reverse(all(r));
		if(s == r){
			palin[s].pb(cost);
		}
		else{
			non[s].pb(cost);
		}
	}
	
	for(auto &x:palin){
		sort(all(x.sc));
	}
	for(auto &x:non){
		sort(all(x.sc));
	}
	
	int ans = 0;
	
	for(auto &x:non){
		string r = x.fr;
		reverse(all(r));
		if(non.count(r)){
			auto &v = non[r];
			while(sz(x.sc) && sz(v)){
				if(x.sc.back() + v.back() > 0){
					ans += x.sc.back() + v.back();
				}
				else{
					break;
				}
				x.sc.ppb();
				v.ppb();
			}
			non.erase(r);
		}
	}
	
	vector<int> choose(1);
	
	for(auto &x:palin){
		while(sz(x.sc) > 1){
			if(x.sc[sz(x.sc)-2] >= 0){
				ans += x.sc.back();
				x.sc.ppb();
				ans += x.sc.back();
				x.sc.ppb();
			}
			else if(x.sc.back() + x.sc[sz(x.sc)-2] > 0){
				ans += x.sc.back() + x.sc[sz(x.sc)-2];
				choose.pb(-x.sc[sz(x.sc)-2]);
				break;
			}
			else{
				choose.pb(x.sc.back());
				break;
			}
		}
		if(sz(x.sc) == 1){
			choose.pb(x.sc.back());
		}
	}
	
	if(sz(choose)){
		sort(all(choose));
		ans += choose.back();
	}
	cout<<ans;
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