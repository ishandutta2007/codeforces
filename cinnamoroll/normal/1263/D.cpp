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
#define MOD 1000000007
//#define MOD 998244353
#define INF (1LL<<60)
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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
typedef pair<int,int> P;
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> s(n);
  REP(i,n) cin >> s[i];
  
  UnionFind uf(n+26);
  vec used(26,0);
  REP(i,n){
    int id = i+26;
    REP(j,s[i].size()){
      uf.unit(s[i][j]-'a',id);
      used[s[i][j]-'a']++;
    }
  }

  int ans = 0;
  set<int> st;
  REP(i,n+26) st.insert(uf.root(i));

  ans = st.size();
  REP(i,26) if(used[i]==0) ans--;

  cout << ans << endl;

  return 0;
}