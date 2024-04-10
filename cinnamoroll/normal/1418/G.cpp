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

// //
// template <typename T,typename E, typename F, typename G, typename H>
// struct SegmentTree{
//   // using F = function<T(T,T)>;
//   // using G = function<T(T,E)>;
//   // using H = function<E(E,E)>;
//   ~~~
// };
//   SegmentTree<int, int, decltype(f), decltype(g), decltype(h)> seg(f,g,h,ti,ei);
template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E,int)>;
  using H = function<E(E,E)>;
  int n;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign((n<<1)-1,ti);
    laz.assign((n<<1)-1,ei);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[(i<<1)+2],dat[(i<<1)|1]);
  }
  void eval(int k,int l,int r){
    if(laz[k]==ei)return;
    dat[k] = g(dat[k], laz[k], r-l);
    if(r-l>1){
      laz[(k<<1)|1] = h(laz[(k<<1)|1], laz[k]);
      laz[(k<<1)+2] = h(laz[(k<<1)+2], laz[k]);
    }
    laz[k]=ei;
  }

  void update(int a, int b, E x,int k=0,int l=0,int r=-1){
    if(r<0)r=n;
    eval(k,l,r);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
      laz[k] = h(laz[k], x);
      eval(k,l,r);
    }
    else {
      update(a,b,x,(k<<1)|1,l,(l+r)/2);
      update(a,b,x,(k<<1)+2,(l+r)/2,r);
      dat[k]=f(dat[(k<<1)|1], dat[(k<<1)+2]);
    }
  }

  T query(int a,int b,int k=0,int l=0,int r=-1){
    if(r<0)r=n;
    eval(k,l,r);
    if(r<=a||b<=l)return ti;
    if(a<=l&&r<=b)return dat[k];
    T xl=query(a,b,(k<<1)|1,l,(l+r)/2);
    T xr=query(a,b,(k<<1)+2,(l+r)/2,r);
    return f(xl, xr);
  }

  //lower_find(l,r,fanc): fanc[0,id)id. ng < ok
  template<typename C>
  int lower_find(int a, int b, C &check, T x, int k=1, int l=0, int r=-1){
    if(r<0)r=n;
    if(!check(f(x,dat[k]))||r<=a||b<=l)return -1;
    if(r-l==1)return l;
    int xl = lower_find(a,b,check,x,(k<<1),l,(l+r)/2);
    if(xl>=0)return xl;
    x = f(x,dat[(k<<1)]);
    return lower_find(a,b,check,x,(k<<1)|1,(l+r)/2,r);
  }
  template<typename C>
  int lower_find(int a, int b, C &check){
    T x=ti;
    return lower_find(a,b,check,x);
  }

  //upper_find(l,r,fanc): fanc[0,id)id. ok < ng
  template<typename C>
  int upper_find(int a, int b, C &check, T x, int k=2, int l=0, int r=-1){
    if(r<0)r=n;
    if(r<=a||b<=l)return -1;
    if(r-l==1)return l;
    if(check(f(x,dat[k]))){
      int xr = upper_find(a,b,check,f(x,dat[k]),((k+1)<<1),(l+r)/2,r);
      if(xr>=0)return xr;
    }
    return upper_find(a,b,check,x,(k<<1),l,(l+r)/2);
  }
  template<typename C>
  int upper_find(int a, int b, C &check){
    T x=ti;
    return upper_find(a,b,check,x);
  }
};

//ex) RAQ & RSQ
//auto f = [](int a, int b){return a+b;};
//auto g = [](int a, int b, int len){return a+b*len;};
//auto h = [](int a, int b){return a+b;};

//ex) RAQ & RMQ
//auto f = [](int a, int b){return min(a,b);};
//auto g = [](int a, int b, int len){return a+b;};
//auto h = [](int a, int b){return a+b;};

void solve(){
  int N;
  cin >> N;

  vector<int> a(N+1);
  REP(i,N) cin >> a[i+1], a[i+1]--;
  
  auto f = [](P a, P b){
    if(a.fs==b.fs) return P(a.fs,a.sc+b.sc);
    else if(a.fs<b.fs) return a;
    else return b;
  };
  auto g = [](P a, int b, int len){
    return P(a.fs+b,a.sc);
  };
  auto h = [](int a, int b){
    return a+b;
  };
  
  SegmentTree<P,int> seg(f,g,h,P(INF,0),0);
  seg.build(vector<P>(N,P(0,1)));
  vec b[N]; REP(i,N) b[i].emplace_back(0);
  int ans = 0;
  FOR2(i,1,N){
    b[a[i]].push_back(i); int sz = b[a[i]].size();
    seg.update(b[a[i]][sz-2],b[a[i]][sz-1],1);
    if(sz >= 4) seg.update(b[a[i]][sz-4],b[a[i]][sz-3],-1);
    if(sz >= 5) seg.update(b[a[i]][sz-5],b[a[i]][sz-4],1);
    P tmp = seg.query(0,i);
    if(tmp.fs==0) ans += tmp.sc;
    // REP(i,N) cout << seg.query(i,i+1).fs << " ";
    // cout << endl;
  }

  cout << ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}