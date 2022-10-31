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
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<P> a(n);
  REP(i,n) cin >> a[i].fs;
  REP(i,n) cin >> a[i].sc;
  
  sort(a.begin(),a.end());
  vec d(n);
  REP(i,n) d[i] = a[i].fs, a[i].fs = i;

  int ans = 0, tmp = d[n-1];
  RREP(i,n-1) ans += tmp - d[i]*(n-1-i), tmp += d[i];

  //debug(ans); 

  auto comp = [](P x, P y){return x.sc < y.sc;};
  sort(a.begin(),a.end(),comp);

  auto f = [](P x, P y){return P(x.fs+y.fs,x.sc+y.sc);};
  SegmentTree<P> L(f,P(0,0)),R(f,P(0,0));
  L.build(vector<P>(n,P(0,0))); R.build(vector<P>(n,P(0,0)));
  int now = a[0].sc, id = n-1;
  RREP(i,n){
    if(now != a[i].sc){
      while(id > i){
        L.update(a[id].fs,P(d[a[id].fs],1));
        id--;
      }
      now = a[i].sc;
    }
    //cout << a[i].fs SP a[i].sc << endl;
    P l = L.query(0,a[i].fs);
    ans -= d[a[i].fs]*l.sc-l.fs;
    //cout << l.fs SP l.sc << endl;
    //debug(ans);
  }

  // REP(i,n){
  //   P r = R.query(a[i].fs,n);
  //   ans -= r.sc-d[a[i].fs]*r.sc;
  //   R.update(a[i].fs,P(d[a[i].fs],1));
  //   debug(ans);
  // }

  cout << ans << endl;

  return 0;
}