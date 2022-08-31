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

int sig[N];
vector<int> g[N];

void dfs(int z){
	for(int x:g[z]){
		sig[x] *= sig[z];
		dfs(x);
	}
}

int dist(int x,int y){
	return x * x + y * y;
}

void solve(){
	int r = 1000000;
	r *= r;
	int n;
	cin >> n;
	
	vector<pii> vec;
	vector<int> ids;
	
	rep(i,0,n){
		int x,y;
		cin >> x >> y;
		vec.pb({x,y});
		ids.pb(i);
		sig[i] = 1;
	}
	
	while(sz(ids) > 2){
		vector<pii> xyz;
		vector<int> tmp;
		rep(i,0,3){
			tmp.pb(ids.back());
			ids.ppb();
			xyz.pb(vec.back());
			vec.ppb();
		}
		bool found = 0;
		rep(i,0,3){
			rep(j,i+1,3){
				int x,y;
				if(dist(xyz[i].fr+xyz[j].fr,xyz[i].sc+xyz[j].sc) <= r){
					// i+j
					g[tmp[i]].pb(tmp[j]);
					found = 1;
					x = xyz[i].fr+xyz[j].fr;
					y = xyz[i].sc+xyz[j].sc;
				}
				else if(dist(xyz[i].fr-xyz[j].fr,xyz[i].sc-xyz[j].sc) <= r){
					// i-j
					sig[tmp[j]] *= - 1;
					g[tmp[i]].pb(tmp[j]);
					found = 1;
					x = xyz[i].fr-xyz[j].fr;
					y = xyz[i].sc-xyz[j].sc;
				}
				if(found == 1){
					int k = 3 - i - j;
					vec.pb(xyz[k]);
					ids.pb(tmp[k]);
					vec.pb({x,y});
					ids.pb(tmp[i]);
					break;
				}
			}
			if(found == 1){
				break;
			}
		}
	}
	if(sz(ids) == 2){
		assert(dist(vec[0].fr,vec[0].sc) <= r);
		assert(dist(vec[1].fr,vec[1].sc) <= r);
		if(dist(vec[0].fr+vec[1].fr,vec[0].sc+vec[1].sc) <= r / 100 * 225){
			// 0+1
			g[ids[0]].pb(ids[1]);
		}
		else if(dist(vec[0].fr-vec[1].fr,vec[0].sc-vec[1].sc) <= r / 100 * 225){
			// 0-1
			sig[ids[1]] *= - 1;
			g[ids[0]].pb(ids[1]);
		}
		ids.ppb();
	}
	
	dfs(ids[0]);
	rep(i,0,n){
		cout << sig[i] << " ";
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