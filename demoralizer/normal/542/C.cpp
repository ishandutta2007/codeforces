#include <bits/stdc++.h>
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

const int N=205;

vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i){
		if (!used[ g[v][i] ]){
			dfs1 (g[v][i]);
		}
	}
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i){
		if (!used[ gr[v][i] ]){
			dfs2 (gr[v][i]);
		}
	}
}

int scc[N];

int dfs(int z){
	if(scc[z])return 0;
	return 1+dfs(g[z][0]);
}

void solve(){
	int n;
	cin>>n;
	g.resize(n+4);
	gr.resize(n+4);
	rep(i,0,n){
		int a;
		cin>>a;
		a--;
		g[i].push_back (a);
		gr[a].push_back (i);
		if(i == a)scc[i]=1;
	}
	
	int ans=1;

	used.assign (n, false);
	for (int i=0; i<n; ++i){
		if (!used[i]){
			dfs1 (i);
		}
	}
	used.assign (n, false);
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
			ans = ans*sz(component)/__gcd(ans,sz(component));
			if(sz(component)>1){
				amax(ans,sz(component));
				for(int x:component){
					scc[x] = 1;
				}
			}
			component.clear();
		}
	}
	
	int ans2=0;
	
	rep(i,0,n){
		if(sz(gr[i]) == 0){
			amax(ans2,dfs(i));
		}
	}
	
	int ans3=ans;
	
	while(ans3<ans2)ans3+=ans;
	
	cout<<ans3;
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