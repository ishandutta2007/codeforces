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

int c[N];
vector<int> v[N];
int tim=0;
int st[N],et[N],ver[N],siz[N];
int cnt[N];
int mx=0;
int sum[N];
int ans[N];
void dfs_sz(int z,int p){
	ver[tim]=z;
	st[z]=tim++;
	siz[z]=1;
	for(int x:v[z]){
		if(x==p)continue;
		dfs_sz(x,z);
		siz[z]+=siz[x];
	}
	et[z]=tim;
}

void add(int z){
	int k=cnt[c[z]]++;
	sum[k]-=c[z];
	sum[k+1]+=c[z];
	if(k==mx)mx++;
}

void remove(int z){
	int k=cnt[c[z]]--;
	sum[k]-=c[z];
	sum[k-1]+=c[z];
	if(k==mx && sum[k]==0)mx--;
}

void dfs(int z,int p,bool keep){
	int big=-1;
	for(int x:v[z]){
		if(x==p)continue;
		if(big == -1 || siz[big] < siz[x])big=x;
	}
	for(int x:v[z]){
		if(x==p || x==big)continue;
		dfs(x,z,0);
	}
	if(big!=-1){
		dfs(big,z,1);
	}
	add(z);
	for(int x:v[z]){
		if(x==p || x==big)continue;
		rep(i,st[x],et[x]){
			add(ver[i]);
		}
	}
	
	ans[z]=sum[mx];
	
	if(!keep){
		rep(i,st[z],et[z]){
			remove(ver[i]);
		}
		
	}
}

void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>c[i];
	}
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs_sz(1,0);
	dfs(1,0,0);
	rep(i,1,n+1){
		cout<<ans[i]<<" ";
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}