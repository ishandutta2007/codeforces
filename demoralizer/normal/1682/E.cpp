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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist=uniform_int_distribution<int>(1,INF);

int h[N];
int p[N]; // cur_val
int par[N];
int num[N];
vector<vector<pii>> v;
vector<set<pii>> s;

int subtree[N];

set<int> relevant;

void dfs(int z,int pr = 0){
	subtree[z] = h[z];
	par[z] = pr;
	for(pii x:v[z]){
		if(x.fr == pr) continue;
		dfs(x.fr,z);
		num[x.fr] = x.sc;
		subtree[z] += subtree[x.fr];
		subtree[z] -= h[p[x.fr]];
		s[z].insert({subtree[x.fr], x.fr});
	}
	relevant.insert(z);
}

void solve(){
	int n,m;
	cin >> n >> m;
	
	v.resize(n + 1);
	s.resize(n + 1);
	
	rep(i,1,n+1){
		cin >> p[i];
		h[i] = dist(rng);
	}
	
	rep(i,1,m+1){
		int x,y;
		cin >> x >> y;
		v[x].pb({y,i});
		v[y].pb({x,i});
	}
	
	rep(i,1,n+1){
		if(par[i]) continue;
		dfs(i);
	}
	
	while(sz(relevant)){
		int z = *relevant.begin();
		relevant.erase(relevant.begin());
		
		// if(z == 1){
		// 	// cout << "HERE " << h[p[z]] << "\n";
		// 	for(auto x:s[z]){
		// 		cout << x << "\n";
		// 	}
		// }
		
		// check
		auto it = s[z].lower_bound({h[p[z]], -1});
		if(it == s[z].end() || it -> fr != h[p[z]]){
			continue;
		}
		int x = it -> sc;
		cout << num[x] << " ";//cout << z << " " << x << "\n";
		if(par[z]){
			s[par[z]].erase({subtree[z],z});
		}
		subtree[z] += h[p[x]];
		swap(p[z], p[x]);
		subtree[z] -= h[p[x]];
		if(par[z]){
			s[par[z]].insert({subtree[z],z});
			relevant.insert(par[z]);
		}
		relevant.insert(z);
		relevant.insert(x);
		// rep(i,1,n+1){
		// 	cout << p[i] << " ";
		// }
		// cout << "\n";
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