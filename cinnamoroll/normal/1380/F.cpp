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
#define ll long long
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

template <typename T, typename F>
struct SegmentTree{
  int n,n_;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
    n_=v.size();
    init();
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void update(int k,T x){
    assert(0 <= k && k < n_);
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  void add(int k,T x){
    assert(0 <= k && k < n_);
    dat[k+=n]+=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T get(int k){
    assert(0 <= k && k < n_);
    return dat[n+k];
  }

  T query(int a,int b){
    assert(0 <= a && a <= b && b <= n_);
    T vl=ti, vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }

  template <class C> int max_right(int l, C check) {
    assert(0 <= l && l <= n_);
    if (l == n_) return n_;
    l += n;
    T sm = ti;
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(f(sm, dat[l]))) {
        while (l < n) {
          l = (2 * l);
          if (check(f(sm, dat[l]))) {
            sm = f(sm, dat[l]);
            l++;
          }
        }
        return l - n;
      }
      sm = f(sm, dat[l]);
      l++;
    } while ((l & -l) != l);
    return n_;
  }

  template <class C> int min_left(int r, C check) {
    assert(0 <= r && r <= n_);
    if (r == 0) return 0;
    r += n;
    T sm = ti;
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(f(dat[r], sm))) {
        while (r < n) {
          r = (2 * r + 1);
          if (check(f(dat[r], sm))) {
            sm = f(dat[r], sm);
            r--;
          }
        }
        return r + 1 - n;
      }
      sm = f(dat[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};

constexpr int mod = 998244353;

void add(int &a, int b){
  a += b;
  if(a > mod) a -= mod;
}

int mul(int a, int b){
  ll res = (ll)a*b;
  if(res > mod) res %= mod;
  return res;
}

void solve(){
  int N,M;
  string S;
  cin >> N >> M >> S;

  auto f = [&](vec &a, vec &b){
    if(a[5]==10) return b;
    if(b[5]==10) return a;
    vec res(6); // [l,r), [l,r-1), [l+1,r), [l+1,r-1), Lchar, Rchar
    add(res[0],mul(a[0],b[0]));
    add(res[1],mul(a[0],b[1]));
    add(res[2],mul(a[2],b[0]));
    add(res[3],mul(a[2],b[1]));
    if(a[5]==1){
      add(res[0],mul(mul(a[1],b[2]),9-b[4]));
      add(res[1],mul(mul(a[1],b[3]),9-b[4]));
      add(res[2],mul(mul(a[3],b[2]),9-b[4]));
      add(res[3],mul(mul(a[3],b[3]),9-b[4]));
    }
    res[4] = a[4];
    res[5] = b[5];
    return res;
  };

  vec E = {1,1,1,0,10,10};
  SegmentTree<vec,decltype(f)> seg(f,E);
  mat a(N,vec(6)); seg.build(a);
  REP(i,N){
    int x = S[i]-'0';
    vec tmp = {x+1,1,1,0,x,x};
    seg.update(i,tmp);
  }

  REP(_,M){
    int x,y; 
    cin >> x >> y; x--;
    vec tmp = {y+1,1,1,0,y,y};
    seg.update(x,tmp);
    cout << seg.query(0,N)[0] << "\n";
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