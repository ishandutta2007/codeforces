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

void add(int &a, int b){
  a = ((a+b) % MOD + MOD) % MOD;
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

vector<int> divisor(const int n){
  vector<int> ret;
  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      ret.pb(i);
      if(i*i!= n) ret.pb(n/i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,k;
  cin >> n >> k;

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  vector<int> div;
  div = divisor(n);

  vector<int> tmp,prob[10000];
  int id = -1;
  for(int i=2;i<=sqrt(n);i+=2){
      int cnt = 0;
      while(n % i == 0){
        n /= i;
        cnt++;
      }
      if(cnt > 0){
        tmp.pb(i); id++;
        REP(_,cnt+1) prob[id].pb(1); 
      }
    if(i == 2) i--;
  }

  if(n != 1){
    id++;
    prob[id].pb(1);
    prob[id].pb(1);
    tmp.pb(n);
  }

  //debug(id);

  
  REP(_,k-1){
    REP(i,id+1){
      vector<int> ret(prob[i].size(),0);
      REP(j,prob[i].size()){
        REP(k,j+1){
          add(ret[k],mul(prob[i][j],mul(prob[i].size(),inv(j+1))));
        }
      }
      prob[i] = ret;
      //REP(j,prob[i].size()) cout << prob[i][j] << " ";
      //cout << endl;
    }
  }

  int p = 0, q = 0;
  REP(i,div.size()){
    int t = div[i], cnt = 1;
    REP(j,tmp.size()){
      int index = 0;
      while(t % tmp[j] == 0){
        index++;
        t /= tmp[j];
      }
      cnt = mul(cnt,prob[j][index]); 
    }
    //debug(cnt);
    add(p,mul(cnt,div[i]%MOD));
    add(q,cnt);
  }

  cout << mul(p,inv(q)) << endl;

  return 0;
}