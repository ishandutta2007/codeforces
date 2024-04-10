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
//                            
//                        
//                
//   
//    
//      
//
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int N = 2e5+10;
vec edge[N],a,sum(N,0),ans(N,0);
int n,m;
map<P,int> mp;

struct UnionFind {
  private:
  vector<int> child,tree,sum;

public:
  UnionFind(int v) {
    tree.resize(v);
    sum.resize(v);
    REP(i,v) tree[i] = i, sum[i] = 1;
  }

  int root(int i){
    if(i == tree[i]){
      REP(j,child.size()) tree[child[j]] = i;
      child.clear(); 
      return i;
    }
    else{
      child.push_back(i);
      return i = root(tree[i]);
    }
  }

  int size(int i){
    return sum[root(i)];
  }

  int unit(int x, int y){
    if(isUnit(x,y)) return 0;
    x = root(x);
    y = root(y);
    sum[min(x,y)] += sum[max(x,y)];
    tree[max(x,y)] = min(x,y);
  }

  bool isUnit(int x, int y){
    return root(x) == root(y);
  }
};

void dfs(int no, int par){
  for(int to:edge[no]){
    if(to == par) continue;
    dfs(to,no);
    int tmp = a[to]-sum[to];
    if(mp.count(P(no,to))) ans[mp[P(no,to)]] = tmp;
    else ans[mp[P(to,no)]] = -tmp;
    sum[no] -= tmp;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  a.resize(n);
  REP(i,n) cin >> a[i];
  
  cin >> m;
  UnionFind uf(n);
  REP(i,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    if(uf.isUnit(x,y)) continue;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
    mp[P(x,y)] = i;
    uf.unit(x,y);
  }

  if(accumulate(a.begin(),a.end(),0LL)){
    cout << "Impossible" << endl;
    return 0;
  }

  cout << "Possible" << endl;

  dfs(0,-1);

  REP(i,m) cout << ans[i] << "\n";

  return 0;
}