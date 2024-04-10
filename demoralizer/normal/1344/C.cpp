#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

vector<int> v[N];
vector<int> rv[N];
int vis[N];

int mn[N];
int rmn[N];

void dfs(int z,int com){
	vis[z]=1;
	mn[z]=z;
	for(int x:v[z]){
		if(vis[x]==1){
			cout<<-1;
			exit(0);
		}
		if(!vis[x]){
			dfs(x,com);
		}
		amin(mn[z],mn[x]);
	}
vis[z]=2;
}

void rdfs(int z,int com){
	vis[z]=com;
	rmn[z]=z;
	for(int x:rv[z]){
		if(!vis[x]){
			rdfs(x,com);
		}
		amin(rmn[z],rmn[x]);
	}
}


void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int j,k;
		cin>>j>>k;
		v[j].pb(k);
		rv[k].pb(j);
	}
	
	rep(i,1,n+1){
		if(vis[i])continue;
		dfs(i,i);
	}
	
	mem0(vis);
	
	rep(i,1,n+1){
		if(vis[i])continue;
		rdfs(i,i);
	}
	
	string pr;
	int cnt=0;
	
	rep(i,1,n+1){
		if(mn[i] == rmn[i] && mn[i] == i) cnt++,pr.pb('A');
		else pr.pb('E');
	}
	
	cout<<cnt<<"\n"<<pr;
	
	
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}