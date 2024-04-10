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

void add(int &a, int b){
  a = ((a+b) % MOD + MOD) % MOD;
}

inline int mul(int a, int b) {
    #if !defined(_WIN32) || defined(_WIN64)
      return (int) ((long long) a * b % MOD);
    #endif
      unsigned long long x = (long long) a * b;
      unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
      asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (MOD)
      );
      return m;
}

inline int modpow(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
      }
      a = mul(a, a);
      b >>= 1;
  }
  return res;
}

inline int inv(int a) {
    a %= MOD;
    if (a < 0) a += MOD;
    int b = MOD, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}

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

  int n,k;
  cin >> n >> k;

  int ans = modpow(n,k);

  UnionFind uf(n);
  REP(i,n-1){
    int x,y,z;
    cin >> x >> y >> z;
    if(z == 0) uf.unit(x-1,y-1);
  }
  
  vec used(n,0);
  REP(i,n){
    int tmp = uf.root(i);
    if(used[tmp]) continue;
    used[tmp]++;
    add(ans,-modpow(uf.size(tmp),k));
  }
  

  cout << ans << endl;

  return 0;
}