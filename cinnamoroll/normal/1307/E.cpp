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
#define INF (1LL<<60)
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
using mint = Fp<0>; // MOD
typedef vector<mint> vec;
typedef vector<vector<mint>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  REP(i,n) cin >> a[i], a[i]--;
  
  map<int,int> mp[n];
  vector<int> x(m),y(m);
  REP(i,m){
    cin >> x[i] >> y[i]; x[i]--;
    mp[x[i]][y[i]] = i;
  }
  
  vector<vector<int>> id(2,vector<int>(n,-1));
  vector<int> cnt(n,0);
  REP(i,n){
    cnt[a[i]]++;
    if(mp[a[i]].count(cnt[a[i]])) id[0][i] = mp[a[i]][cnt[a[i]]];
  }

  cnt.assign(n,0);
  RREP(i,n){
    cnt[a[i]]++;
    if(mp[a[i]].count(cnt[a[i]])) id[1][i] = mp[a[i]][cnt[a[i]]];
  }

  vec ans(n+1,0); int mx = 0;
  set<int> L[n],R[n];
  REP(i,n) if(id[1][i]!=-1) R[x[id[1][i]]].insert(id[1][i]);

  mint p = 1;
  REP(i,n) if(R[i].size()) mx++, p *= R[i].size();
  ans[mx] += p;

  REP(i,n){
    if(id[1][i]!=-1) R[x[id[1][i]]].erase(R[x[id[1][i]]].find(id[1][i]));
    if(id[0][i]==-1) continue; 
    int sum = 0; mint now = 1;
    REP(j,n){
      if(j==x[id[0][i]]){
        if(R[j].size()==0) sum++;
        else if(R[j].size()==1&&R[j].find(id[0][i])!=R[j].end()) sum++;
        else sum += 2, now *= R[j].size()-(R[j].find(id[0][i])!=R[j].end());
      }
      else{
        if(!L[j].size() && !R[j].size()) ;
        else if(!L[j].size()) sum++, now *= R[j].size();
        else if(!R[j].size()) sum++, now *= L[j].size();
        else if(L[j].size()==1&&R[j].size()==1){
          if(*L[j].begin()==*R[j].begin()) sum++, now *= 2;
          else sum += 2;
        }
        else{
          sum += 2; int tmp = 0;
          ITR(itr,L[j]) tmp += R[j].size()-(R[j].find(*itr)!=R[j].end());
          now *= tmp;
        }
      }
    }
    L[x[id[0][i]]].insert(id[0][i]);
    ans[sum] += now;
    chmax(mx,sum);
  }

  cout << mx SP ans[mx] << endl;

  return 0;
}