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

const int N=1e5+5;

map<int, vector<pair<int, pii>>> g[2];

void solve(){
	int n,w,h;
	cin >> n >> w >> h;
	vector<pii> ans(n);
	rep(i,0,n){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		pii tmp;
		if(a){
			tmp = {w,b};
		}
		else{
			tmp = {b,h};
		}
		assert(tmp.fr != 0);
		// cout << i << " " << a << "\n";
		g[a][c-b].pb({i,tmp});
	}
	rep(z,0,2){
		for(auto &x:g[z]){
			sort(all(x.sc),[&](pair<int, pii> a, pair<int, pii> b){
				return a.sc < b.sc;
			});
		}
	}
	rep(z,0,2){
		for(auto x:g[z]){
			int c1 = sz(g[!z][x.fr]);
			int c2 = sz(x.sc);
			rep(i,0,sz(x.sc)){
				// cout << x.sc[i].fr << "\n";
				if(c2 > c1){
					ans[x.sc[i].fr] = x.sc[i+c1].sc;
				}
				else{
					ans[x.sc[i].fr] = g[!z][x.fr][c2-1].sc;
				}
				c2--;
			}
		}
	}
	for(auto x:ans){
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
	//cin>>t;
	while(t--) solve();
	return 0;
}