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

int a[N],x;

vector<pii> v[N];
int parent[N],siz[N];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i]=findParent(parent[i]);
	return parent[i];
}
void unionNodes(int A,int B)
{
	int parent_a=findParent(A),parent_b=findParent(B);
	if(parent_a==parent_b)
		return;
	if(siz[parent_a]>=siz[parent_b]){
		swap(parent_a,parent_b);
	}
	siz[parent_b]+=siz[parent_a];
	a[parent_b] += a[parent_a] - x;
	assert(a[parent_b] >= 0);
	if(sz(v[parent_b]) < sz(v[parent_a])){
		swap(v[parent_b],v[parent_a]);
	}
	for(auto x:v[parent_a]){
		v[parent_b].pb(x);
	}
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
	}
}

vector<int> ans;
void solve(){
	int n,m;
	cin >> n >> m >> x;
	int tot = 0;
	rep(i,1,n+1){
		cin >> a[i];
		tot += a[i];
	}
	
	if(tot < x * (n - 1)){
		cout << "NO\n";
		return;
	}
	
	cleardsu(n);
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		v[x].pb({y,i});
		v[y].pb({x,i});
	}
	
	set<pii,greater<pii> > s;
	rep(i,1,n+1){
		s.insert({a[i],i});
	}
	
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(s.begin());
		int ver = cur.sc;
		// cout << ver
		while(!v[ver].empty()){
			int adj = v[ver].back().fr;
			int id = v[ver].back().sc;
			v[ver].ppb();
			if(findParent(adj) == findParent(ver)){
				continue;
			}
			ans.pb(id+1);
			int par = findParent(adj);
			s.erase({a[par],par});
			unionNodes(ver,adj);
			par = findParent(ver);
			s.insert({a[par],par});
			break;
		}
	}
	
	cout << "YES\n";
	for(int x:ans){
		cout << x << "\n";
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