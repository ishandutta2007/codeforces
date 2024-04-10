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
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
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

template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void update(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  void add(int k,T x){
    dat[k+=n]+=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
  //lower_find(l,r,fanc): fanc[0,id)id. ng < ok
  template<typename C>
  int lower_find(int a, int b, C &check, T x, int k=1, int l=0, int r=-1){
    if(r<0) r=n;
    if(!check(f(x,dat[k]))||r<=a||b<=l) return -1;
    if(r-l==1) return r;
    int xl = lower_find(a,b,check,x,(k<<1),l,(l+r)/2);
    if(xl>=0)return xl;
    x = f(x,dat[(k<<1)]);
    return lower_find(a,b,check,x,(k<<1)|1,(l+r)/2,r);
  }
  template<typename C>
  int lower_find(int a, int b, C &check){
    T x=ti;
    if(check(x)) return a;
    return lower_find(a,b,check,x);
  }

  //upper_find(l,r,fanc): fanc[id,N)id. ok < ng
  template<typename C>
  int upper_find(int a, int b, C &check, T x, int k=1, int l=0, int r=-1){
    if(r<0)r=n;
    if(!check(f(x,dat[k]))||r<=a||b<=l) return -1;
    if(r-l==1) return l;
    int xr = upper_find(a,b,check,x,(k<<1)|1,(l+r)/2,r);
    if(xr>=0)return xr;
    x = f(x,dat[(k<<1)|1]);
    return upper_find(a,b,check,x,(k<<1),l,(l+r)/2);
  }
  template<typename C>
  int upper_find(int a, int b, C &check){
    T x=ti;
    if(check(x)) return b;
    return upper_find(a,b,check,x);
  }
};

int N;
vector<P> get(int l,int r){
  vector<P> res;
  while(l<r){
    RREP2(i,N){
      if(l%(1<<i) || l+(1<<i) > r) continue;
      res.push_back(P(l,(1<<i)));
      l += (1<<i);
      break;
    }
  }
  return res;
}

void solve(){
  int Q;
  cin >> N >> Q;

  vector<int> a(1<<N);
  REP(i,1<<N) cin >> a[i];

  auto f = [](int a, int b){return a+b;};
  SegmentTree<int> seg(f,0);
  seg.build(a);

  int mask = 0;
  REP(_,Q){
    int q; cin >> q;
    if(q==1){
      int x,k; cin >> x >> k; x--;
      seg.update(x^mask,k);
    }
    if(q==2){
      int k; cin >> k;
      mask ^= ((1<<k)-1);
    }
    if(q==3){
      int k; cin >> k;
      mask ^= (1<<k);
    }
    if(q==4){
      int l,r; cin >> l >> r; l--;
      int ans = 0;
      vector<P> p = get(l,r); 
      for(P x:p){
        int u = (mask^x.fs)/x.sc*x.sc;
        ans += seg.query(u,u+x.sc);
      }
      cout << ans << endl;
    }
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}