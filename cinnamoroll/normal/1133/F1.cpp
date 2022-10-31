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
#define fs first
#define sc second
#define pb push_back
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //
  //DP

  int n,m;
  cin >> n >> m;

  vec edge[n];
  REP(_,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }

  int mx = 0, id = -1;
  REP(i,n) if(mx < edge[i].size()) mx = edge[i].size(), id = i;

  UnionFind uf(n);
  vector<P> ans;
  for(int no:edge[id]){
    uf.unit(no,id);
    ans.push_back(P(no+1,id+1));
  }

  REP(i,n){
    for(int no:edge[i]){
      if(uf.isUnit(no,i)) continue;
      ans.push_back(P(no+1,i+1));
      uf.unit(no,i);
    }
  }

  REP(i,n-1) cout << ans[i].fs SP ans[i].sc << endl;

  return 0;
}