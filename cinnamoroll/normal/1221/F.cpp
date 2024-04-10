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

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}

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

  int n;
  cin >> n;

  using T = tuple<int,int,int>;
  vector<T> t(n);
  vec x;
  REP(i,n){
    int a,b,c;
    cin >> a >> b >> c;
    if(a > b) swap(a,b);
    t[i] = T(a,b,c);
    x.push_back(b);
  }

  sort(t.begin(),t.end());

  auto r = compress(x);
  auto v = dict(r);

  int N = v.size();

  vector<P> sum(N+1,P(0,0));
  REP(i,n){
    int a,b,c;
    tie(a,b,c) = t[i];
    sum[v[b]].fs += c;
  }

  REP(i,N) sum[i+1].fs += sum[i].fs;
  REP(i,N) sum[i].fs -= r[i], sum[i].sc = i;

  //REP(i,N) cout << sum[i] << endl;

  auto f = [](P a, P b){return max(a,b);};
  auto g = [](P a, int b, int len){return P(a.fs+b,a.sc);};
  auto h = [](int a, int b){return a+b;};
  SegmentTree<P,int> seg(f,g,h,P(-INF,-INF),0);
  seg.build(sum);

  int ans = 0, id = 0,id2 = 0,L = 0,R = 0;
  REP(i,n){
    int a,b,c;
    tie(a,b,c) = t[i];
    //cout << a SP b SP c << endl;
    while(id < n){
      int u,o,w;
      tie(u,o,w) = t[id];
      if(u >= a) break;
      seg.update(v[o],N,-w);
      id++;
    }
    while(id2<N && r[id2] < a) id2++;
    P p = seg.query(id2,N);
    int now = p.fs+a;
    //cout << now << endl;
    if(ans < now){
      ans = now;
      L = a;
      R = r[p.sc];
    }
  }

  if(ans == 0){
    cout << ans << endl;
    cout << (int)2e9 SP (int)2e9 SP (int)2e9 SP (int)2e9 << endl;
  }

  else{
    cout << ans << endl;
    cout << L SP L SP R SP R << endl;
  }

  return 0;
}