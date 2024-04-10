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

const int N=1e6+5;

int calc(int x){
	int L=0,U=2e4,n=0;
	while(L<=U){
		int m=(L+U)/2;
		if(x>m*(m+1)/2){
			L=m+1;
			n=m;
		}
		else{
			U=m-1;
		}
	}
	int ans = x*(n+1) - n*(n+1)*(n+2)/6;
	return ans;
}

pair<pii, int> e[N];
vector<int> g[N],gr[N],order;
bool used[N];
int comp[N];

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v,int c) {
	used[v] = true;
	comp[v] = c;
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i],c);
}

vector<pii> v[N];
int val[N];
int dp[N];
bool vis[N];
void dfs(int z){
	vis[z] = 1;
	int ans = 0;
	for(pii x:v[z]){
		if(!vis[x.fr])dfs(x.fr);
		amax(ans,dp[x.fr]+x.sc);
	}
	dp[z] = ans+val[z];
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		cin>>e[i];
		g[e[i].fr.fr].pb(e[i].fr.sc);
		gr[e[i].fr.sc].pb(e[i].fr.fr);
	}
	rep(i,1,n+1){
		if(!used[i]){
			dfs1(i);
		}
	}
	int cnt = 1;
	mem0(used);
	rep(i,1,n+1){
		int v = order.back();
		order.ppb();
		if(!used[v]){
			dfs2(v,cnt++);
		}
	}
	
	rep(i,0,m){
		int x=comp[e[i].fr.fr], y=comp[e[i].fr.sc];
		if(x == y){
			val[x] += calc(e[i].sc);
		}
		else{
			v[x].pb({y,e[i].sc});
		}
	}
	
	int s;
	cin>>s;
	dfs(comp[s]);
	cout<<dp[comp[s]];
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