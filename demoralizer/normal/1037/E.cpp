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

int rem[N];
int deg[N];
vector<pii> v[N];

void solve(){
	vector<pii> edgs;
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		edgs.pb({x,y});
		v[x].pb({y,i});
		v[y].pb({x,i});
	}
	
	set<pii> s;
	vector<int> ans;
	rep(i,1,n+1){
		deg[i] = sz(v[i]);
		s.insert({deg[i],i});
	}
	
	while(sz(edgs)){
		while(sz(s) && s.begin()->fr < k){
			int z = s.begin()->sc;
			s.erase(s.begin());
			for(pii x:v[z]){
				if(rem[x.sc]) continue;
				rem[x.sc] = 1;
				s.erase({deg[x.fr],x.fr});
				deg[x.fr]--;
				s.insert({deg[x.fr],x.fr});
			}
		}
		
		ans.pb(sz(s));
		
		pii x = edgs.back();
		edgs.ppb();
		rem[sz(edgs)] = 1;
		if(s.count({deg[x.fr],x.fr}) && s.count({deg[x.sc],x.sc})){
			s.erase({deg[x.fr],x.fr});
			s.erase({deg[x.sc],x.sc});
			deg[x.fr]--;
			deg[x.sc]--;
			s.insert({deg[x.fr],x.fr});
			s.insert({deg[x.sc],x.sc});
		}
	}
	
	reverse(all(ans));
	for(int x:ans){
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