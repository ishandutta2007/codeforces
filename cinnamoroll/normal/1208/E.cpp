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
  template<typename C>
  int find(int a, int b, C &check, T x, int k=1, int l=0, int r=-1){
    if(r<0)r=n;
    if(!check(f(x,dat[k]))||r<=a||b<=l)return -1;
    if(r-l==1)return l;
    int xl = find(a,b,check,x,(k<<1),l,(l+r)/2);
    if(xl>=0)return xl;
    x = f(x,dat[(k<<1)]);
    return find(a,b,check,x,(k<<1)|1,(l+r)/2,r);
  }
  template<typename C>
  int find(int a, int b, C &check){
    T x=ti;
    return find(a,b,check,x);
  }
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,w;
  cin >> n >> w;

  vec ans(w+10,0);
  REP(_,n){
    int l;
    cin >> l;
    vector<int> a(l);
    REP(i,l) cin >> a[i];
    int mx = w-l+1;
    multiset<int> st; int id = 0;
    bool flag = false;
    REP(i,l){
      st.insert(a[i]);
      while(i-id>=mx) st.erase(st.find(a[id])), id++;
      //debug(*st.rbegin());
      if(0 > *st.rbegin()){
        if(max(i,w-i-1) >= l){ flag = true; continue;}
      }
      flag = false;
      ans[i] += *st.rbegin();
      if(i != l-1) ans[i+1] -= *st.rbegin();
    }
    int v = *st.rbegin();
    if(v < 0) {
      if(!flag) ans[l] -= v;
      continue;
    }
    REP(i,l) if(a[i] == v) id = i; 
    st.clear();
    FOR(i,id+1,l) st.insert(a[i]);
    int cnt = w-(l-id-1);ans[cnt] -= v;
    //debug(id);debug(cnt);
    FOR(i,id+1,l){
      //debug(*st.find(a[i]));
      if(*st.rbegin() < 0){  
        if(max(cnt,w-cnt-1) >= l){
          st.erase(st.find(a[i]));continue;
        }
      }
      ans[cnt] += *st.rbegin(), ans[cnt+1] -= *st.rbegin(),st.erase(st.find(a[i])),cnt++;
    }
  }

  REP(i,w-1) ans[i+1] += ans[i];

  REP(i,w) cout << ans[i] << " ";
  cout << endl;

  return 0;
}