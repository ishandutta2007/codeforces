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

  int n,m,d;
  cin >> n >> m >> d;

  UnionFind uf1(n),uf2(n);
  vec edge[n];
  REP(_,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
    if(x && y) uf1.unit(x,y); //1
  }

  vector<P> ans;
  for(int no:edge[0]){
    if(uf1.isUnit(0,no)) continue;
    uf1.unit(0,no);
    uf2.unit(0,no);
    ans.push_back(P(no+1,1));
  }

  // or 
  if(edge[0].size() < d || ans.size() > d){
    cout << "NO" << endl;
    return 0;
  }

  //d
  for(int no:edge[0]){
    if(ans.size() == d) break;
    if(uf2.isUnit(0,no)) continue;
    uf2.unit(0,no);
    ans.push_back(P(no+1,1));
  }

  FOR(i,1,n){
    for(int no:edge[i]){
      if(uf2.isUnit(no,i) || no == 0) continue;
      ans.push_back(P(no+1,i+1));
      uf2.unit(no,i);
    }
  }

  cout << "YES" << endl;
  REP(i,n-1) cout << ans[i].fs SP ans[i].sc << endl;

  return 0;
}