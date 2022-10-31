// warm heart, wagging tail,and a smile just for you!
//                                                                     
//                                                                   
//                                                                
//                                                   
//                                      
//                               
//                             
//                           
//                         
//                       
//                     
//                 
//     
//   
// 
// 
// 
// 
//   
//         
//                                                        
//
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<ll,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
const int N = 1e5+10;
vector<P> edge[N];
vector<ll> dist(N,INF);
int n,m,k,q;
 
void bfs(){
  priority_queue<P,vector<P>,greater<P>> que;
  REP(i,k){
    for(P to:edge[i]) que.push(to);
  }
  while(que.size()){
    P x = que.top(); que.pop();
    if(dist[x.sc]!=INF) continue;
    dist[x.sc] = x.fs;
    for(P to:edge[x.sc]){
      que.push(P(to.fs+x.fs,to.sc));
    }
  }
}
 
class PartiallyPersistentUnionFindTree {
public:
	using size_type = std::uint_fast32_t;
 
private:
	std::vector<std::pair<size_type, size_type>> tree;
	std::vector<std::vector<std::pair<size_type, size_type>>> siz;
	size_type global_count;
 
public:
	PartiallyPersistentUnionFindTree(const size_type size)
		: tree(size, std::make_pair(1, std::numeric_limits<size_type>::max())),
		siz(size, std::vector<std::pair<size_type, size_type>>(
			1, std::make_pair(0, 1))),
		global_count(0) {}
	size_type find(const size_type ver, size_type x) const {
		assert(x < tree.size());
		while (tree[x].second <= ver)
			x = tree[x].first;
		return x;
	}
	bool unit(size_type x, size_type y) {
		assert(x < tree.size());
		assert(y < tree.size());
		++global_count;
		x = find(global_count, x);
		y = find(global_count, y);
		if (x == y)
			return false;
		if (tree[x].first < tree[y].first)
			std::swap(x, y);
		tree[x].first += tree[y].first;
		siz[x].emplace_back(global_count, tree[x].first);
		tree[y] = std::make_pair(x, global_count);
		return true;
	}
	bool isUnit(const size_type ver, const size_type x, const size_type y) const {
		assert(x < tree.size());
		assert(y < tree.size());
		return find(ver, x) == find(ver, y);
	}
	size_type size(const size_type ver, size_type x) const {
		assert(x < tree.size());
		x = find(ver, x);
		return (std::lower_bound(siz[x].begin(), siz[x].end(),
			std::make_pair(ver+1, static_cast<size_type>(0)))-1)
			->second;
	}
	
	size_type count() const { return global_count; }
	size_type query(const size_type ver, size_type x, size_type y)const {
		x = find(ver, x);
		y = find(ver, y);
		if (x == y) return size(ver, x);
		return size(ver, x) + size(ver, y);
	}
};
/*

: PartiallyPersistentUnionFindTree uf(n);
isUnit(ver,x,y) verunitx,y
*/
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  cin >> n >> m >> k >> q;
 
  vec x(m),y(m),w(m);
  REP(i,m){
    cin >> x[i] >> y[i] >> w[i];
    x[i]--; y[i]--;
    edge[x[i]].push_back(P(w[i],y[i]));
    edge[y[i]].push_back(P(w[i],x[i]));
  }
 
  REP(i,k) dist[i] = 0;
  
  bfs();
 
  //REP(i,n) cout << dist[i] << endl;
 
  using T = tuple<ll,int,int>;
  vector<T> a(m);
  REP(i,m){
    a[i] = T(w[i]+dist[x[i]]+dist[y[i]],x[i],y[i]);
  }
  sort(a.begin(),a.end());
 
  PartiallyPersistentUnionFindTree uf(n);
  vector<ll> ans(m);
 
  REP(i,m){
    int u,v;
    ll c;
    tie(c,u,v) = a[i];
    ans[i] = c;
    uf.unit(u,v);
  }
 
  REP(_,q){
    int s,t;
    cin >> s >> t; s--; t--;
    int ng = 0, ok = m;
    while (abs(ng-ok)>1) {
      int mid = (ng+ok)/2;
      (uf.isUnit(mid,s,t)?ok:ng) = mid;
    }
    cout << ans[ok-1] << "\n";
  }
 
  return 0;
}