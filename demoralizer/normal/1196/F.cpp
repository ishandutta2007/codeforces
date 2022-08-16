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

const int N=2e5+5;

int vis[N];
vector<pii> v[N];

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<pair<int, pii>> edgs;
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		edgs.pb({w,{x,y}});
	}
	sort(all(edgs));
	
	int L = 0, U = 1e15;
	int ans;
	while(L <= U){
		int m = (L + U) / 2;
		vector<int> ver;
		int j = 0;
		while(j < sz(edgs) && j < k && edgs[j].fr <= m){
			int x = edgs[j].sc.fr;
			int y = edgs[j].sc.sc;
			int w = edgs[j].fr;
			v[x].pb({y,w});
			v[y].pb({x,w});
			ver.pb(x);
			ver.pb(y);
			j++;
		}
		sort(all(ver));
		uniq(ver);
		// cout << L << " " << m << " " << U << " " << sz(ver) << "\n";
		int paths = 0;
		if(j == k){
			paths = k;
		}
		else{
			for(int x:ver){
				for(int y:ver){
					vis[y] = 0;
				}
				set<pii> s; // {dist,ver}
				s.insert({0,x});
				while(!s.empty()){
					int z = s.begin()->sc;
					int d = s.begin()->fr;
					s.erase(s.begin());
					if(vis[z]) continue;
					vis[z] = 1;
					if(d && d <= m){
						paths++;
					}
					for(auto y:v[z]){
						s.insert({d + y.sc,y.fr});
					}
				}
			}
			paths /= 2;
		}
		
		// cout << paths << "\n";
		
		for(int x:ver){
			v[x].clear();
		}
		if(paths >= k){
			ans = m;
			U = m - 1;
		}
		else{
			L = m + 1;
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