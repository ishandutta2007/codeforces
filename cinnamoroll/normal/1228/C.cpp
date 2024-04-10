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
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
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
    while(x%p==0) x /= p, cnt++;
    if(cnt) mp[p] = cnt;
  }
  if(x != 1) mp[x] = 1;
  return mp;
}

bool over_frow(int a, int b){
  if(a == 0 || b == 0) return false;
  return a > __LONG_LONG_MAX__/b;
}

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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x,n;
  cin >> x >> n;

  init(100000);

  map<int,int> mp = Primefactorization(x);

  int ans = 1;
  ITR(itr,mp){
    int now = itr->fs;
    while(now <= n){
      ans = mul(ans,modpow(itr->fs,n/now));
      if(over_frow(now,itr->fs)) break;
      now *= itr->fs;
    }
  }

  cout << ans << endl;

  return 0;
}