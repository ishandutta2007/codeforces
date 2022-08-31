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

#define SIZE   N
#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

int A[SIZE];

int query(int i) // Returns the sum from index 1 to i
{
	int sum = 0;
	while (i > 0) 
		sum += A[i], i -= LSB(i);
	return sum;
}
void update(int i, int k) // Adds k to element with index i
{
	if(i<1)return;
	while (i < SIZE) 
		A[i] += k, i += LSB(i);
}

struct que
{
	int v,k,id;
};

vector<int> v[N];
vector<que> q[N];
int st[N],et[N],ver[N],siz[N],c[N],ans[N],tim=1;
void dfssz(int z,int p){
	ver[tim]=z;
	st[z]=tim++;
	siz[z]=1;
	for(int x:v[z]){
		if(x==p)continue;
		dfssz(x,z);
		siz[z]+=siz[x];
	}
	et[z]=tim;
}

int cnt[N],cntcnt[N];
void add(int z){
	cnt[c[z]]++;
	cntcnt[cnt[c[z]]]++;
}
void remove(int z){
	cntcnt[cnt[c[z]]]--;
	cnt[c[z]]--;
}

void dfs(int z,int p,bool keep){
	int big=-1;
	for(int x:v[z]){
		if(x==p)continue;
		if(big==-1 || siz[x] > siz[big])
			big=x;
	}
	
	for(int x:v[z]){
		if(x==p || x==big)continue;
		dfs(x,z,0);
	}
	if(big!=-1){
		dfs(big,z,1);
	}
	
	for(int x:v[z]){
		if(x==p || x==big)continue;
		rep(i,st[x],et[x]){
			add(ver[i]);
		}
	}
	add(z);
	
	for(auto x:q[z]){
		ans[x.id]=cntcnt[x.k];
	}
	
	if(!keep){
		rep(i,st[z],et[z]){
			remove(ver[i]);
		}
	}
	
}


void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1){
		cin>>c[i];
	}
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rep(i,0,m){
		que x;
		x.id=i;
		cin>>x.v>>x.k;
		q[x.v].pb(x);
	}
	
	dfssz(1,0);
	dfs(1,0,1);
	
	rep(i,0,m){
		cout<<ans[i]<<"\n";
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