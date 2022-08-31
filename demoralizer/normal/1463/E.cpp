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

const int N=3e5+5;

vector<int> v[N];

int vr[N];

int c[N];
int cr[N];

int n;
int vis[N];

bool dfs(int z){
	vis[z] = 1;
	for(int x:v[z]){
		if(vis[x] == 2) continue;
		if(vis[x] == 1) return 1;
		if(dfs(x)) return 1;
	}
	vis[z] = 2;
	return 0;
}

bool cycle(){
	mem0(vis);
	rep(i,1,n+1){
		if(vis[i]) continue;
		if(dfs(i)) return 1;
	}
	return 0;
}


int parent[N],siz[N];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i]=findParent(parent[i]);
	return parent[i];
}
void unionNodes(int a,int b)
{
	int parent_a=findParent(a),parent_b=findParent(b);
	if(parent_a==parent_b)
		return;
	if(siz[parent_a]>=siz[parent_b]){
		swap(parent_a,parent_b);
	}
	for(int x:v[parent_a]){
		v[parent_b].pb(x);
	}
	siz[parent_b]+=siz[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
	}
}

vector<int> order;
void topo(int z){
	vis[z] = 1;
	for(int x:v[z]){
		if(vis[x]) continue;
		topo(x);
	}
	order.pb(z);
}

vector<pii> prs;

void solve(){
	int k;
	cin >> n >> k;
	
	cleardsu(n);
	
	rep(i,1,n+1){
		int p;
		cin >> p;
		v[p].pb(i);
		vr[i] = p;
	}
	
	rep(i,0,k){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		prs.pb({x,y});
		assert(c[x] == 0 && cr[y] == 0);
		c[x] = y;
		cr[y] = x;
	}
	
	if(cycle()){
		cout << 0;
		return;
	}
	
	for(auto z:prs){
		unionNodes(z.fr,z.sc);
	}
	rep(i,1,n+1){
		if(i != findParent(i)) continue;
		for(int &x:v[i]){
			x = findParent(x);
		}
	}
	mem0(vis);
	rep(i,1,n+1){
		if(i != findParent(i) || vis[i]) continue;
		topo(i);
	}
	
	reverse(all(order));
	
	vector<int> ans;
	
	for(int x:order){
		while(cr[x]) x = cr[x];
		while(x){
			ans.pb(x);
			x = c[x];
		}
	}
	
	mem0(vis);
	vis[0] = 1;
	for(int x:ans){
		if(!vis[vr[x]]){
			cout << 0;
			return;
		}
		vis[x] = 1;
	}
	
	for(int x:ans){
		cout << x << " ";
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