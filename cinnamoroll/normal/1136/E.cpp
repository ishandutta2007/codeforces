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

struct LazySegmentTree {
  private:
    int n;
    vector<int> node, lazy;

public:
  LazySegmentTree(vector<int> v) {
    int sz = (int)v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1);
    lazy.resize(2*n-1, -INF);

    REP(i,sz) node[i+n-1] = v[i];
    RREP(i,n-1) node[i] = node[i*2+1] + node[i*2+2];
  }

  void eval(int k, int l, int r) {
    if(lazy[k] != -INF) {
      node[k] = (r-l)*lazy[k];
      if(r - l > 1) {
        lazy[2*k+1] = lazy[k];
        lazy[2*k+2] = lazy[k];
      }
      lazy[k] = -INF;
    }
  }

  void update(int a, int b, int x, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    eval(k, l, r);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {
      lazy[k] = x;
      eval(k, l, r);
    }
    else {
      update(a, b, x, 2*k+1, l, (l+r)/2);
      update(a, b, x, 2*k+2, (l+r)/2, r);
      node[k] = node[2*k+1] + node[2*k+2];
    }
  }

  int query(int a, int b, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    eval(k, l, r);
    if(b <= l || r <= a) return 0;
    if(a <= l && r <= b) return node[k];
    int vl = query(a, b, 2*k+1, l, (l+r)/2);
    int vr = query(a, b, 2*k+2, (l+r)/2, r);
    return vl + vr;
  }
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vec a(n);
  REP(i,n) cin >> a[i];
  
  vec k(n-1);
  REP(i,n-1) cin >> k[i];
  vec sk(n,0);
  REP(i,n-1) sk[i+1] = sk[i] + k[i];
  vec ssk(n+1,0);
  REP(i,n) ssk[i+1] = ssk[i] + sk[i];

  //k
  REP(i,n) a[i] -= sk[i];
  
  int q;
  cin >> q;

  vector<char> query(q);
  vec x(q), y(q);
  REP(i,q) cin >> query[i] >> x[i] >> y[i];

  LazySegmentTree seg(a);
  REP(i,q){
    if(query[i] == 's'){
      //k
      cout << seg.query(x[i]-1,y[i]) + (ssk[y[i]]-ssk[x[i]-1]) << endl;
    }
    else{
      //x[i]
      int tmp = seg.query(x[i]-1,x[i]) + y[i];
      //
      int ng = n, ok = x[i]-1;
      while (abs(ng-ok)>1) {
        int mid = (ng+ok)/2;
        (seg.query(mid,mid+1) < tmp?ok:ng) = mid;
      }
      seg.update(x[i]-1,ok+1,tmp);
    }
  }

  return 0;
}