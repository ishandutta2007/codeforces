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
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> x(n+1,0),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  auto v = compress(x);
  auto r = dict(v);

  int m = r.size();

  auto f = [](int a, int b){return a+b;};
  SegmentTree<int> seg(f,0);
  seg.build(vec(m,0));
  
  priority_queue<P> que;
  REP(i,n) que.push(P(y[i],r[x[i]]));

  int ans = 0;
  while(que.size()){
    vec tmp = {0}; int now = que.top().fs;
    while(que.size() && que.top().fs == now) tmp.push_back(que.top().sc), que.pop();
    sort(tmp.begin(),tmp.end());
    for(int k:tmp) if(seg.query(k,k+1) == 0) seg.add(k,1);
    REP(i,tmp.size()-1) ans += seg.query(tmp[i]+1,tmp[i+1]+1)*seg.query(tmp[i+1],m);
    //debug(ans);
  }

  cout << ans << endl;

  return 0;
}