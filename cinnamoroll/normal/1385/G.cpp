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
#include "bits/stdc++.h"
using namespace std;
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

struct UnionFind {
  private:
  vector<int> child,tree;
  vector<vector<int>> list;

public:
  UnionFind(int v) {
    tree.resize(v);
    list.resize(v);
    REP(i,v) tree[i] = i, list[i].push_back(i);
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
    return list[root(i)].size();
  }

  vector<int> nodes(int no){
    return list[root(no)];
  }

  bool unit(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y) return false;
    if(list[x].size() < list[y].size()) swap(x,y);
    for(int no:list[y]) list[x].emplace_back(no);
    tree[y] = x;
    return true;
  }

  bool isUnit(int x, int y){
    return root(x) == root(y);
  }
};

void solve(){
  int N;
  cin >> N;

  vector<P> a[N];
  REP(i,2) REP(j,N){
    int x; cin >> x;
    a[x-1].emplace_back(i,j);
  }

  UnionFind uf(2*N);
  REP(i,N){
    if(a[i].size()!=2){
      cout << -1 << endl;
      return;
    }
    P x = a[i][0], y = a[i][1];
    if(x.fs==y.fs){
      uf.unit(x.sc,y.sc+N);
      uf.unit(x.sc+N,y.sc);
    }
    else{
      uf.unit(x.sc,y.sc);
      uf.unit(x.sc+N,y.sc+N);      
    }
  }

  vec r[2*N], ans, f(N,0);
  REP(i,2*N) r[uf.root(i)].push_back(i);
  REP(i,2*N){
    vec x, y;
    if(r[i].size() && f[r[i][0]%N]) continue;
    for(int v:r[i]) (v<N?x:y).push_back(v%N), f[v%N]++;
    if(x.size()>y.size()) swap(x,y);
    for(int v:x) ans.push_back(v);
  }

  sort(ans.begin(),ans.end());

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i]+1 << " ";
  cout << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}