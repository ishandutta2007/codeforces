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

  int n,m;
  cin >> n >> m;

  if(n==1){
    cout << 0 << endl;
    return 0;
  }

  vector<int> a(m);
  REP(i,m) cin >> a[i],a[i]--;

  vec v(n+m+10,0);
  REP(i,n) v[n+m+9-i] = 1;
  
  auto f = [](int a,int b){return a+b;};
  SegmentTree<int> seg(f,0);
  seg.build(v);

  int ans = n;
  int l = m+10, r = n+m+10-1;
  //
  REP(i,m){
    ans += seg.query(l,r);
    int id = a[i]+l;
    int tmp = seg.query(id-1,id);
    ans -= tmp;
    seg.update(id-1,0);
    seg.add(id-2,tmp);
    l--; r--;
   // debug(ans);
  }
  ans += seg.query(l,r);
//debug(ans);

  v.assign(n+m+10,0);
  REP(i,n) v[i] = 1;
  seg.build(v);
  l = 1, r = n;
  //
  REP(i,m){
    ans += seg.query(l,r);
    int id = a[i]+l-1;
    int tmp = seg.query(id+1,id+2);
    ans -= tmp;
    seg.update(id+1,0);
    seg.add(id+2,tmp);
    l++; r++;
    //debug(ans);
  } 
  ans += seg.query(l,r);

  cout << ans << endl;

  return 0;
}