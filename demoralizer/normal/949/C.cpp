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

int u[N];
int comp[N];
int vis[N];

vector<int> v[N],vr[N];
vector<int> topo,component;

void dfs1(int z,int p = 0){
	vis[z]=1;
	for(int x:v[z]){
		if(vis[x])continue;
		dfs1(x,z);
	}
	topo.pb(z);
}

void dfs2(int z,int p = 0){
	vis[z]=1;
	for(int x:vr[z]){
		if(vis[x])continue;
		dfs2(x,z);
	}
	component.pb(z);
}

void solve(){
	int n,m,h;
	cin>>n>>m>>h;
	rep(i,1,n+1){
		cin>>u[i];
	}
	
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		if((u[x]+1)%h == u[y]){
			v[x].pb(y);
			vr[y].pb(x);
		}
		if((u[y]+1)%h == u[x]){
			v[y].pb(x);
			vr[x].pb(y);
		}
	}
	
	int ans = INF;
	int com;
	
	rep(i,1,n+1){
		if(!vis[i])dfs1(i);
	}
	reverse(all(topo));
	mem0(vis);
	for(int z:topo){
		if(vis[z])continue;
		dfs2(z);
		for(int x:component) comp[x] = z;//,cout<<x<<" ";cout<<"\n";
		bool take = 1;
		for(int x:component){
			for(int y:v[x]){
				if(comp[y] != z){
					take = 0;
				}
			}
		}
		if(take){
			if(sz(component)<ans){
				ans = sz(component);
				com = z;
			}
		}
		component.clear();
	}
	
	cout<<ans<<"\n";
	rep(i,1,n+1){
		if(comp[i] == com){
			cout<<i<<" ";
		}
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