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
#define INF (1<<30)
#define fs first
#define sc second
//#define int long long
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


template <typename T,typename E, typename F, typename G, typename H>
struct SegmentTree{
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
 
signed main(){
  //ios::sync_with_stdio(false);
  //cin.tie(0);
 
  int n;
  char s[(int)1e6+10];
  scanf("%d",&n);
  scanf("%s",s);
  
  int N = (n+10)/2;
  vec sum(N,0);
  auto f = [](int a, int b){return min(a,b);};
  auto ff = [](int a, int b){return max(a,b);};
  auto g = [](int a, int b, int len){return a+b;};
  auto h = [](int a, int b){return a+b;};
  SegmentTree<int,int,decltype(f), decltype(g), decltype(h)> mn(f,g,h,INF,0);
  SegmentTree<int,int,decltype(ff), decltype(g), decltype(h)> mx(ff,g,h,-INF,0);
  mn.build(sum); mx.build(sum);
 
  int id = 1, mxx = 1;
  int cnt = 0;
  string t(N,'-');
  REP(i,n){
    if(s[i]=='('){
      int v = 1;
      if(t[id]=='(') v--;
      if(t[id]==')') v++;t[id] = s[i];
      cnt += v;
      mn.update(id,N,v); mx.update(id,N,v);
    }
    else if(s[i]==')'){
      int v = -1;
      if(t[id]=='(') v--;
      if(t[id]==')') v++;t[id] = s[i];
      cnt += v;
      mn.update(id,N,v); mx.update(id,N,v);
    }
    else if(s[i]=='L') id = max(1,id-1);
    else if(s[i]=='R') id++;
    else {
      int v = 0;
      if(t[id]=='(') v--;
      if(t[id]==')') v++;
      t[id] = s[i];
      cnt += v;
      mn.update(id,N,v); mx.update(id,N,v);      
    }
    mxx = max(mxx,id);
    if(cnt==0 && mn.query(0,mxx+1)>=0) printf("%d ",mx.query(0,mxx+1));
    else printf("%d ",-1);
  }
 
  return 0;
}