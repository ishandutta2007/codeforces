#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
// #define int               long long
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

template<typename T,typename T1>
T amax(T &a,T1 b){
	a=max(a,b);
	return a;
}

template<typename T,typename T1>
T amin(T &a,T1 b){
	a=min(a,b);
	return a;
}

const int N=5005;

vector<pii> v[N];
int par[N];
int edg[N];
int lev[N];

int b[N];
void dfs(int z,int p,int e,int l){
	edg[z]=e;
	par[z]=p;
	lev[z]=l;
	for(pii x:v[z]){
		if(x.fr==p)continue;
		dfs(x.fr,z,x.sc,l+1);
	}
}
void solve(){
	int n;
	cin>>n;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb({y,i});
		v[y].pb({x,i});
	}
	rep(i,1,n)b[i]=1;
	dfs(1,1,0,0);
	
	vector<pair<pii, int>> q;
	int m;
	cin>>m;
	rep(zzz,0,m){
		int x,y,g;
		cin>>x>>y>>g;
		q.pb({{x,y},g});
		while(x!=y){
			if(lev[x]<lev[y]){
				swap(x,y);
			}
			else{
				amax(b[edg[x]],g);
				x=par[x];
			}
		}
	}
	for(pair<pii, int> w:q){
		int x,y,g;
		x=w.fr.fr;
		y=w.fr.sc;
		g=w.sc;
		int ans=1e6;
		while(x!=y){
			if(lev[x]<lev[y]){
				swap(x,y);
			}
			else{
				amin(ans,b[edg[x]]);
				x=par[x];
			}
		}
		if(g!=ans){
			cout<<-1;
			return;
		}
	}
	rep(i,1,n){
		cout<<b[i]<<" ";
	}
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