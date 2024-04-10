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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
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

  int unit(int x, int y){
    x = root(x);
    y = root(y);
    sum[min(x,y)] += sum[max(x,y)];
    tree[max(x,y)] = min(x,y);
  }

  bool isUnit(int x, int y){
    return root(x) == root(y);
  }
};

const int NMAX = 2e5+10;
vector<P> edge[NMAX];

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  UnionFind uf0(n), uf1(n);
  REP(i,n-1){
    int x,y,c;
    cin >> x >> y >> c;
    x--; y--;
    edge[x].push_back(P(y,c));
    edge[x].push_back(P(x,c));
    if(c == 0) uf0.unit(x,y);
    else uf1.unit(x,y);
  }

  int ans = 0;
  vec flag0(n,0),flag1(n,0);
  REP(i,n){
    int r = uf0.root(i);
    if(flag0[r] == 0){
      flag0[r] = uf0.size(r);
      ans += flag0[r]*(flag0[r]-1);
    }
    r = uf1.root(i);
    if(flag1[r] == 0){
      flag1[r] = uf1.size(r);
      ans += flag1[r]*(flag1[r]-1);
    }
  }

  REP(i,n){
    int u = uf0.root(i), v = uf1.root(i);
    ans += (flag0[u]-1)*(flag1[v]-1);
  }

  cout << ans << endl;

  return 0;
}