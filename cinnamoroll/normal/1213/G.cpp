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

  bool unit(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y) return false;
    sum[min(x,y)] += sum[max(x,y)];
    tree[max(x,y)] = min(x,y);
    return true;
  }

  bool isUnit(int x, int y){
    return root(x) == root(y);
  }
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  using T = tuple<int,int,int>;
  vector<T> a(n-1);
  REP(i,n-1){
    int x,y,z;
    cin >> x >> y >> z;
    a[i] = T(z,x-1,y-1);
  }

  vector<P> b(m);
  REP(i,m) cin >> b[i].fs, b[i].sc = i;

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  UnionFind uf(n);

  vec ans(m); int id = 0, sum = 0;
  REP(i,n-1){
    int x,y,z;
    tie(z,x,y) = a[i];
    while(id<m && z > b[id].fs) ans[b[id].sc] = sum, id++;
    if(id == m) break;
    sum += uf.size(x)*uf.size(y);
    uf.unit(x,y);
  }

  FOR(i,id,m) ans[b[i].sc] = sum;

  REP(i,m) cout << ans[i] << " ";
  cout << endl;

  return 0;
}