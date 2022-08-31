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

const int N=2e5+5;

vector<vector<pii>> v;
int p[N];
int dis[N];
int ans[N];
int cur_time;

int parent[N],siz[N];
vector<set<int>> queries;

void merge(set<int> &a, set<int> &b){
	if(sz(a) < sz(b)){
		swap(a,b);
	}
	// put b in a
	for(int x:b){
		if(a.count(x)){
			ans[x] = cur_time;
			a.erase(x);
		}
		else{
			a.insert(x);
		}
	}
}

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
	siz[parent_b]+=siz[parent_a];
	parent[parent_a]=parent_b;
	merge(queries[parent_b], queries[parent_a]);
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
	}
	queries.resize(n + 1);
}

void solve(){
	v.resize(N);
	int n,m,k,q;
	cin >> n >> m >> k >> q;
	
	cleardsu(k);
	
	rep(i,0,m){
		int x,y,w;
		cin >> x >> y >> w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	
	set<array<int,3>> s; //{dist, vertex, parent}
	rep(i,1,k+1){
		s.insert({0,i,i});
	}
	
	vector<array<int,3>> edges; // {len, x, y}
	
	while(sz(s)){
		auto tmp = *s.begin();
		s.erase(s.begin());
		int z = tmp[1];
		if(p[z]){
			if(tmp[2] != p[z]){
				edges.pb({tmp[0] + dis[z], p[z], tmp[2]});
			}
			continue;
		}
		p[z] = tmp[2];
		dis[z] = tmp[0];
		
		for(pii x:v[z]){
			s.insert({dis[z] + x.sc, x.fr, p[z]});
		}
	}
	
	sort(all(edges));
	rep(i,0,q){
		int x,y;
		cin >> x >> y;
		queries[x].insert(i);
		queries[y].insert(i);
	}
	for(auto e:edges){
		cur_time = e[0];
		unionNodes(e[1],e[2]);
	}
	
	rep(i,0,q){
		cout << ans[i] << "\n";
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