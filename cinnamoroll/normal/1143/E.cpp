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

struct SegmentTree {
  private:
    int n;
    vector<int> node;

public:
  SegmentTree(vector<int> v) {
    int sz = (int)v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1);

    REP(i,sz) node[i+n-1] = v[i];
    RREP(i,n-1) node[i] = min(node[i*2+1],node[i*2+2]); //max
  }

  // 0_indexedka
  void update(int k, int a){
    k += n-1;
    node[k] = a;
    while(k > 0){
      k = (k-1) / 2;
      node[k] = min(node[k*2+1],node[k*2+2]); //max
    }
  }

  // [l,r)[a,b)
  int query(int a, int b, int k=0, int l=0, int r=-1){
    if(r < 0) r = n;
    if(r <= a || b <= l) return INF; // -INF
    if(a <= l && r <= b) return node[k];
    else{
      int vl = query(a,b,k*2+1,l,(l+r)/2);
      int vr = query(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr); //max
    }
  }
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m,q;
  cin >> n >> m >> q;

  vec p(n);
  REP(i,n) cin >> p[i];
  
  vec a(m);
  REP(i,m) cin >> a[i];

  vec fol(n+1); //i1
  REP(i,n) fol[p[i]] = p[(i+1)%n];

  int d = log2(n)+1;
  mat next(m,vec(d,INF)); //next[i][j] -> i2^jindex
  vec id(n+1,INF);
  RREP(i,m){
    id[a[i]] = i;
    next[i][0] = id[fol[a[i]]];
  }
  FOR(i,1,d){
    REP(j,m){
      int in = j; //index
      REP(_,2) if(in != INF) in = next[in][i-1];
      next[j][i] = in;
    }
  }

  vec tmp(m);
  REP(i,m){
    int cur = i, sum = 0;
    RREP(j,d){
      if(sum + pow(2,j) > n-1) continue;
      if(cur == INF) break;
      cur = next[cur][j];
      sum += pow(2,j);
    }
    tmp[i] = cur;
  }

  SegmentTree seg(tmp);
  REP(_,q){
    int l,r;
    cin >> l >> r;
    if(seg.query(l-1,r) < r) cout << 1;
    else cout << 0;
  }
  cout << endl;

  return 0;
}