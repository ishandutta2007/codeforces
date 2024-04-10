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
#define MOD 1000003
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
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
    if(a < 0) add(a,0); 
    if(b < 0) add(b,0);
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

  int n = 11;
  vec x(n),y(n);
  
  REP(i,n){
    cout << "?" SP i+1 << endl;
    cout.flush();
    cin >> y[i];
    x[i] = i+1;
  }

  vector<int> in(n);
  REP(i,n){
    int tmp = 1;
    REP(j,n) if(i != j) tmp = mul(tmp,x[i]-x[j]);
    in[i] = inv(tmp);
  }

  REP(i,MOD){
    int sum = 0;
    REP(j,n){
      int tmp = y[j];
      REP(k,n) if(j != k) tmp = mul(tmp,i-x[k]);
      add(sum,mul(tmp,in[j]));
    } 

    if(sum != 0) continue;
    cout << "!" SP i << endl;
    cout.flush();
    return 0;
  }

  cout << "!" SP -1 << endl;
  cout.flush();
  return 0;
}