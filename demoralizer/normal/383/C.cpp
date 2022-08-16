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

#define SIZE   N
#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one
struct  fenwick
{
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
		while (i < SIZE) 
			A[i] += k, i += LSB(i);
	}
}f[2];

struct query
{
	int type,time,value,node;
};

int a[N];
int dep[N];
int ans[N];
bool pr[N];

vector<int> v[N];
vector<query> queries[N];
void dfs(int z,int p){
	dep[z]=dep[p]+1;
	
	for(auto q:queries[z]){
		if(q.type==1){
			f[dep[z]&1].update(q.time,q.value);
			f[!(dep[z]&1)].update(q.time,-q.value);
		}
	}
	for(auto q:queries[z]){
		if(q.type==2){
			ans[q.time] = a[z] + f[dep[z]&1].query(q.time);
			pr[q.time] = 1;
		}
	}
	
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
	}
	
	
	for(auto q:queries[z]){
		if(q.type==1){
			f[dep[z]&1].update(q.time,-q.value);
			f[!(dep[z]&1)].update(q.time,q.value);
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1){
		cin>>a[i];
	}
	
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	rep(i,1,m+1){
		query q;
		q.time=i;
		cin>>q.type>>q.node;
		if(q.type==1){
			cin>>q.value;
		}
		queries[q.node].pb(q);
	}
	
	dfs(1,0);
	
	rep(i,1,m+1){
		if(pr[i]){
			cout<<ans[i]<<"\n";
		}
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