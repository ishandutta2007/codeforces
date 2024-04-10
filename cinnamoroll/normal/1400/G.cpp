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

vector<int> MODS = { 1000000007, 998244353 }; // 
template<int IND = 0> struct Fp {
    long long val;
    
    int MOD = MODS[IND];
    constexpr Fp(long long v = 0) noexcept : val(v % MODS[IND]) {
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
using mint = Fp<1>; // MOD
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

P f(int l1, int r1, int l2, int r2){
  if(l1 > l2) swap(l1,l2), swap(r1,r2);
  if(!range(l2,l1,r1+1)) return P(-1,-1);
  else return P(l2,min(r1,r2));
}

void solve(){
  int N,M;
  cin >> N >> M;

  init(N*2);

  vector<int> l(N),r(N),a(N+5,0);
  REP(i,N){
    cin >> l[i] >> r[i];
    a[l[i]]++;
    a[r[i]+1]--;
  }

  vector<int> u(M),v(M);
  REP(i,M) cin >> u[i] >> v[i], u[i]--, v[i]--;
  
  REP(i,N+4) a[i+1] += a[i];

  mat b(41,vec(N+1,0)); // ij
  REP(i,41) FOR(j,1,N+1) b[i][j] = cmb(a[j]-i,j-i);
  REP(i,41) FOR(j,1,N) b[i][j+1] += b[i][j];

  mint ans = 0;
  REP(i,1<<M){
    P x = P(1,N); set<int> st;
    REP(j,M){
      if(!parity(i,j)) continue;
      x = f(x.fs,x.sc,l[u[j]],r[u[j]]);
      x = f(x.fs,x.sc,l[v[j]],r[v[j]]);
      st.insert(u[j]); st.insert(v[j]);
    }
    if(x.fs==-1) continue; 
    int sz = st.size();
    if(pcnt(i)%2) ans -= b[sz][x.sc] - b[sz][x.fs-1];
    else ans += b[sz][x.sc] - b[sz][x.fs-1];
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