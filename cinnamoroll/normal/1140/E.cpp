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
#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void add(int &a, int b){
  a = ((a+b) % MOD + MOD) % MOD;
}

inline int mul(int a, int b) {
    add(a,0); add(b,0);
    #if !defined(_WIN32) || defined(_WIN64)
      return (int) ((long long) a * b % MOD);
    #endif
      unsigned long long x = (long long) a * b;
      unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
      asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (MOD)
      );
      return m;
}

inline int modpow(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
      }
      a = mul(a, a);
      b >>= 1;
  }
  return res;
}

inline int inv(int a) {
    a %= MOD;
    if (a < 0) a += MOD;
    int b = MOD, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}

int calc2(int len, int k){
  mat dp(len+1,vec(2,0));
  dp[0][0] = 1;
  REP(i,len){
    dp[i+1][0] = mul(dp[i][1],k-1); //
    dp[i+1][1] = (dp[i][0]+mul(dp[i][1],k-2))%MOD; //
  }
  return mul(dp[len][1],k-1);
}

int calc3(int len, int k){
  mat dp(len+1,vec(3,0));
  dp[0][0] = 1;
  REP(i,len){
    dp[i+1][0] = (dp[i][1]+mul(dp[i][2],k-2))%MOD; //
    dp[i+1][1] = (dp[i][0]+mul(dp[i][2],k-2))%MOD; //
    dp[i+1][2] = (dp[i][0]+dp[i][1]+mul(dp[i][2],k-3))%MOD; //
  }
  return (dp[len][0]+mul(dp[len][2],k-2))%MOD;
}

int calc(vec &a, int k){
  int n = a.size();
  int l = n, r = -1;
  REP(i,n){
    if(a[i] == -1) continue;
    l = min(i,l);
    r = i;
  }
  int res;
  //-1
  if(r == -1){
    res = k;
    REP(i,n-1) res = mul(res,k-1);
  }
  else{
    res = 1;
    REP(i,l) res = mul(res,k-1);
    FOR(i,r+1,n) res = mul(res,k-1);
    //-1
    FOR(i,l+1,r+1){
      if(a[i] == -1) continue;
      //
      if(a[l] == a[i]) res = mul(res,calc2(i-l-1,k));
      //
      else res = mul(res,calc3(i-l-1,k));
      l = i;
    }
  }
  return res;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  vec a[2];
  REP(i,n){
    int x;
    cin >> x;
    a[i%2].push_back(x);
  }

  cout << mul(calc(a[0],k),calc(a[1],k)) << endl;

  return 0;
}