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

vector<int> pri;
void init(int x){
  vector<bool> flag(x+1,false);
  for(int i = 2; i <= x; i++){
    if(flag[i]) continue;
    pri.emplace_back(i);
    for(int j = i; j <= x; j+=i) flag[j] = true;
  }
}
 
map<long long,int> Primefactorization(long long x){
  map<long long, int> mp;
  for(int p:pri){
    int cnt = 0;
    if(p*p > x) break;
    while(x%p==0) x /= p, cnt++;
    if(cnt) mp[p] = cnt;
  }
  if(x != 1) mp[x] = 1;
  return mp;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int d,q;
  cin >> d >> q;

  init(35000000);

  vec fact(1000010,1), inv(1000010,1);
  REP(i,1000001) fact[i+1] = fact[i]*(i+1), inv[i+1] /= fact[i+1];

  map<int,mint> memo;

  REP(_,q){
    int x,y;
    cin >> x >> y;
    if(x<y) swap(x,y);
    mint res = 1;
    if(x%y){
      int g = __gcd(x,y);
      x /= g; y /= g;
      if(memo.count(x)) res *= memo[x];
      else{
        auto v = Primefactorization(x);
        mint tmp = 1;
        int sum = 0;
        ITR(itr,v) sum += itr->sc, tmp *= inv[itr->sc];
        tmp *= fact[sum];
        memo[x] = tmp; res *= tmp;
      }
      if(memo.count(y)) res *= memo[y];
      else{
        auto v = Primefactorization(y);
        mint tmp = 1;
        int sum = 0;
        ITR(itr,v) sum += itr->sc, tmp *= inv[itr->sc];
        tmp *= fact[sum];
        memo[y] = tmp; res *= tmp;
      }
    }
    else{
      if(memo.count(x/y)) res = memo[x/y];
      else{
        auto v = Primefactorization(x/y);
        int sum = 0;
        ITR(itr,v) sum += itr->sc, res *= inv[itr->sc];
        res *= fact[sum];
        memo[x/y] = res;
      }
    }
    cout << res << "\n";
  }

  return 0;
}