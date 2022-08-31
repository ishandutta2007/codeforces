#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}
const int N=1e5+5;

int n,m,d;
vector<int> v[N];
int dis[N];
multiset<int> r[N];
void dfs(int z,int par){
	r[z].insert(dis[z]);
	for(int x:v[z]){
		if(x==par)continue;
		dfs(x,z);
		r[z].insert(dis[x]+1);
		dis[z]=max(dis[z],1+dis[x]);
	}
}
void dfs2(int z,int par,int c){
	dis[z]=max(dis[z],c+1);
	r[z].insert(1+c);
	for(int x:v[z]){
		if(x==par)continue;
		auto it=r[z].rbegin();
		if(*it==1+dis[x])it++;
		dfs2(x,z,*it);
	}
}
void solve(){
	cin>>n>>m>>d;
	rep(i,0,N)dis[i]=-M;
	rep(i,0,m){
		int x;
		cin>>x;
		dis[x]=0;
	}
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	dfs2(1,0,-M);
	int ans=0;
	rep(i,1,n+1){
		ans+=(dis[i]<=d);
	}
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}