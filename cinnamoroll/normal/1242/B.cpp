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
const double EPS = 1e-9;
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
 
template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
 
template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n,m;
  cin >> n >> m;
  vec edge[n];
  vec x(m),y(m);
  REP(i,m){
    cin >> x[i] >> y[i]; x[i]--; y[i]--;
    edge[x[i]].push_back(y[i]);
    edge[y[i]].push_back(x[i]);
  }
  
  int id, mn = INF;
  REP(i,n) if(mn > edge[i].size()) id = i, mn = edge[i].size();
 
  set<int> st;
  REP(i,n) st.insert(i);
  for(int no:edge[id]) st.erase(st.find(no));
 
  vec tmp = edge[id];
  tmp.push_back(id);
  auto r = compress(tmp);
  auto v = dict(r);
 
  int N = v.size();
  //debug(N); debug(id);
  UnionFind uf(N);
  vec edge2[N];
  REP(i,m){
    if(st.find(x[i]) != st.end()) x[i] = id;
    if(st.find(y[i]) != st.end()) y[i] = id;
    //cout << x[i] SP y[i] << endl;
    edge2[v[x[i]]].push_back(v[y[i]]);
    edge2[v[y[i]]].push_back(v[x[i]]);
  }
 
  REP(i,N){
    int cnt = 0;
    for(int no:edge2[i]) if(no==v[id]) cnt++;
    if(cnt < st.size()) uf.unit(i,v[id]);
    vec now = compress(edge2[i]);
    int in = 0;
    REP(j,N){
      if(in < now.size() && j == now[in]) in++;
      else uf.unit(i,j);
    }
  }
 
  set<int> stt;
  REP(i,N) stt.insert(uf.root(i));
 
  cout << stt.size()-1 << endl;
 
  return 0;
}