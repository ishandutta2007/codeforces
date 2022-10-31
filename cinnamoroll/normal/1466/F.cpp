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

constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
template<int IND = 0> struct Fp {
    long long val;
    
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<IND>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<IND>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<IND> modpow(const Fp<IND> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = Fp<0>;
typedef vector<mint> vec;
typedef vector<vector<mint>> mat;
vec fact,inv;
void init(int n){
  fact.assign(n+1,1);
  inv.assign(n+1,1);
  REP(i,n) fact[i+1] = fact[i]*(i+1), inv[i+1] /= fact[i+1];
}

mint cmb(int n, int r){
  if(n < r || r < 0) return 0;
  return fact[n]*inv[r]*inv[n-r];
}
mint cmb2(int n, int r){
  mint res = 1;
  for(int i = 0; i < r; i++){
    res *= n-i;
    res /= i+1;
  }
  return res;
}

struct UnionFind {
  private:
  vector<int> child,tree;
  vector<vector<int>> list;
 
public:
  UnionFind(int v) {
    tree.resize(v);
    list.resize(v);
    REP(i,v) tree[i] = i, list[i].push_back(i);
  }
 
  int root(int i){
    if(i == tree[i]){
      REP(j,child.size()) tree[child[j]] = i;
      child.clear(); 
      return i;
    }
    else{
      child.push_back(i);
      return i = root(tree[i]);
    }
  }
 
  int size(int i){
    return list[root(i)].size();
  }
 
  vector<int> nodes(int no){
    return list[root(no)];
  }
 
  bool unit(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y) return false;
    if(list[x].size() < list[y].size()) swap(x,y);
    for(int no:list[y]) list[x].emplace_back(no);
    tree[y] = x;
    return true;
  }
 
  bool isUnit(int x, int y){
    return root(x) == root(y);
  }
};

void solve(){
  int N,M;
  cin >> N >> M;

  vector<int> b(M,0);

  vector<int> ans;
  UnionFind uf(M);
  REP(i,N){
    int k; cin >> k;
    if(k==1){
      int x; cin >> x;
      x--;
      int r = uf.root(x);
      if(!b[r]) b[r]++, ans.emplace_back(i);
    }
    else{
      int x,y; cin >> x >> y;
      x--; y--;
      int v = b[uf.root(x)] + b[uf.root(y)];
      if(v==2) continue;
      if(uf.unit(x,y)){
        ans.emplace_back(i);
        if(v) b[uf.root(x)] = 1;
      }
    }
  }

  mint res = 1;
  vector<int> sum(M,0);
  vector<int> flag(M,0);
  REP(i,M){
    int r = uf.root(i);
    sum[r]++;
    if(b[i]) flag[r] = 1;
  }

  REP(i,M){
    if(sum[i]==0) continue;
    int tmp = sum[i] + flag[i] -1;
    res *= modpow((mint)2,tmp);
  } 

  cout << res SP ans.size() << endl;

  sort(ans.begin(),ans.end());

  REP(i,ans.size()) cout << ans[i]+1 << " ";
  cout << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}