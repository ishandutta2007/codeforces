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

  vector<int> a(m),b(m);
  REP(i,m) cin >> a[i] >> b[i];
  
  UnionFind uf(n+1);
  vector<P> c(m);
  REP(i,m){
    uf.unit(a[i],b[i]);
    if(a[i]>b[i]) swap(a[i],b[i]);
    c[i] = P(a[i],b[i]);
  }

  sort(c.begin(),c.end());

  int ans = 0, l = c[0].fs, r = c[0].sc;
  FOR(i,1,m){
    if(c[i].fs <= r) r = max(r,c[i].sc);
    else{
      set<int> st;
      //cout << l SP r << endl;
      FOR(j,l,r+1) st.insert(uf.root(j));
      ans += st.size()-1;
      l = c[i].fs; r = c[i].sc;
    }
  }

    set<int> st;
    FOR(j,l,r+1) st.insert(uf.root(j));
    ans += st.size()-1;

    cout << ans << endl;

  return 0;
}