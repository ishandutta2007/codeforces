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
#define INF 1LL<<60
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
#define range(i,a,b) (a)<=(i) && (i)<(b)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

int add(int a, int b){
  return ((a+b) % MOD + MOD) % MOD;
}

inline int mul(int a, int b) {
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  string s;
  cin >> n >> s;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int dp[n+1][4] = {};
  REP(i,n){
    REP(j,4) dp[i+1][j] = dp[i][j];
    if(s[i] == 'h'){
      dp[i+1][0] = dp[i][0]+a[i];
      //dp[i+1][1] = dp[i][0];
    }
    if(s[i] == 'a'){
      dp[i+1][1] = dp[i][1]+a[i];
      //dp[i+1][2] = dp[i][1];
    }
    if(s[i] == 'r'){
      dp[i+1][2] = dp[i][2]+a[i];
     // dp[i+1][3] = dp[i][2];
    }
    if(s[i] == 'd') dp[i+1][3] = dp[i][3]+a[i];

    REP(j,3) dp[i+1][j+1] = min(dp[i+1][j],dp[i+1][j+1]);
  }

  cout << min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]}) << endl;

  return 0;
}