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

int a[N];
int par[N];
int dep[N];
vector<int> v[N];
set<pair<pii, int>> s;
map<int, int> cnt;

int best = 0;
int lower = 1;
bool found = 0;

void dfs(int z,int p){
	par[z] = p;
	dep[z] = dep[p] + 1;
	auto it = s.lower_bound({{a[z],N},0});
	if(it != s.begin()){
		it--;
		if(it->fr.fr == a[z]){
			if(it->fr.sc >= dep[best]){
				best = it->sc;
				found = 1;
				lower = z;
			}
		}
	}
	s.insert({{a[z],dep[z]},z});
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		dfs(x,z);
	}
	s.erase({{a[z],dep[z]},z});
}

int roots = 0;

void dfs2(int z,int p){
	if(cnt[a[z]] == 1){
		roots++;
	}
	for(int x:v[z]){
		if(x == p || cnt[a[x]] > 1){
			continue;
		}
		dfs2(x,z);
	}
}

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> a[i];
		cnt[a[i]]++;
	}
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(1,0);
	while(par[lower] != best){
		lower = par[lower];
	}
	
	dfs2(lower,best);
	
	found = 0;
	dep[best] = 0;
	dfs(best,lower);
	
	if(found == 1){
		roots = 0;
	}
	
	cout << roots;
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