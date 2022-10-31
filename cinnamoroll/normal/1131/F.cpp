#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
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
  vector<int> child,tree;
  mat ans;

public:
  UnionFind(int v) {
    tree.resize(v);
    REP(i,v) tree[i] = i;
    ans.resize(v);
    REP(i,v) ans[i].push_back(i);
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

  int unit(int x, int y){
    int s = root(x);
    int t = root(y);
    if(ans[s].size() > ans[t].size()){
      REP(j,ans[t].size()) ans[s].push_back(ans[t][j]);
      tree[t] = s;
    }
    else{ 
      REP(j,ans[s].size()) ans[t].push_back(ans[s][j]);
      tree[s] = t;
    }
  }

  void solve(int n){
    REP(i,n){
      if(ans[i].size() < n) continue;
      REP(j,n) cout << ans[i][j]+1 << " ";
      cout << endl;
    }
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

  int n;
  cin >> n;

  vec x(n-1),y(n-1);
  REP(i,n-1){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }
  
  UnionFind uf(n);
  
  REP(i,n-1) uf.unit(x[i],y[i]);
  
  uf.solve(n);

  return 0;
}