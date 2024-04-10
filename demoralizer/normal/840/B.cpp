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

const int N=3e5+5;

set<int> ans;
int d[N],par[N];
vector<pii> v[N];int vis[N];
void dfs(int z,int p,int e){
	vis[z]=1;
	for(pii x:v[z]){
		if(vis[x.fr])continue;
		dfs(x.fr,z,x.sc);
	}
	if(d[z] != -1 && d[z] != par[z]){
		par[p]^=1;
		ans.insert(e);
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	int r = 1;
	rep(i,1,n+1){
		cin>>d[i];
		if(d[i] == -1) r=i;
	}
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[x].pb({y,i+1});
		v[y].pb({x,i+1});
	}
	dfs(r,0,0);
	if(d[r] == -1 || par[0] == 0){
		cout<<sz(ans)<<"\n";
		for(int x:ans){
			cout<<x<<" ";
		}
	}
	else{
		cout<<-1;
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