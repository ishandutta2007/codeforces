#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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
const int32_t MM=998244353;

const int N=22;
const int M=(1<<N);

int parent[M],size[M],vis[M],pres[M];
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
	if(size[parent_a]>=size[parent_b]){
		swap(parent_a,parent_b);
	}
	size[parent_b]+=size[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(){
	for(int i=0;i<M;i++){
		parent[i]=i;
		size[i]=1;
	}
}

int n,m;
void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	rep(i,0,n){
		if(x>>i&1){
			int y = x^(1<<i);
			if(!pres[y]) continue;
			unionNodes(x,y);
			dfs(y);
		}
	}
}

void dfs0(int x){
	if(vis[x]) return;
	vis[x] = 1;
	rep(i,0,n){
		if(x>>i&1){
			int y = x^(1<<i);
			dfs0(y);
			pres[x] |= pres[y];
		}
	}
}


void solve(){
	cleardsu();
	cin>>n>>m;
	vector<int> a(m);
	int full = (1<<n) - 1;
	auto inv = [&](int x){
		return x ^ full;
	};
	
	
	for(int &x:a){
		cin>>x;
		pres[x] = 1;
	}
	
	dfs0(full);
	mem0(vis);
	
	for(int x:a){
		// cout << x << " " << inv(x) << " " << pres[inv(x)] << "\n";
		if(!pres[inv(x)]) continue;
		unionNodes(x,inv(x));
		dfs(inv(x));
	}
	
	set<int> s;
	for(int x:a){
		s.insert(findParent(x));
	}
	cout << sz(s);
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