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

const int N=1e5+5;

vector<pii> v[100005];
int vis[100005];
int d[N];

vector<int> basis;
void insert(int n){
	for(int x:basis){
		amin(n,x^n);
	}
	if(n){
		basis.pb(n);
	}
}

void dfs(int z,int val){
	vis[z]=1;
	d[z]=val;
	for(pii x:v[z]){
		if(vis[x.fr]){
			insert(val^d[x.fr]^x.sc);
			continue;
		}
		dfs(x.fr,val^x.sc);
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	
	dfs(1,0);
	int ans=d[n];
	// sort(all(basis),greater<int>());
	for(int x:basis){
		amin(ans,ans^x);
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}