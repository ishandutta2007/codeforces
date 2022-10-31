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

  template<typename C>
  int find(int a, int b, C &check, T x, int k=0, int l=0, int r=-1){
    if(r<0)r=n;
    eval(k,l,r);
    if(!check(f(x,dat[k]))||r<=a||b<=l)return -1;
    if(r-l==1)return l;
    int xl = find(a,b,check,x,(k<<1)|1,l,(l+r)/2);
    if(xl>=0)return xl;
    x = f(x,dat[(k<<1)|1]);
    return find(a,b,check,x,(k<<1)+2,(l+r)/2,r);
  }

  //find(l,r,fanc): fanc[0,id)id
  //
  template<typename C>
  int find(int a, int b, C &check){
    T x=ti;
    return find(a,b,check,x);
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  string s;
  cin >> n >> k >> s;

  auto f = [](int a, int b){return min(a,b);};
  auto g = [](int a, int b, int len){return min(a,b);};
  auto h = [](int a, int b){return min(a,b);};
  SegmentTree<int,int> seg(f,g,h,INF,INF);
  seg.build(vec(n+1,INF));

  seg.update(0,1,0);
  FOR(i,1,n+1){
    int l = max(1LL,i-k),r = min(i+k,n+1)+1; //[l,r)
    if(s[i-1]=='0') l = i, r = i+1;
    //cout << l SP r << endl;
    seg.update(i,r,seg.query(l-1,i)+i);
  }

  cout << seg.query(n,n+1) << endl;

  return 0;
}