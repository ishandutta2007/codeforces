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
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int extgcd(int a, int b, int& x, int& y) {
  if (a < b) return extgcd(b, a, y, x);
  if (b > 0) {
    int g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  } else {
    x = 1, y = 0;
    return a;
  }
}

int extgcd2(int a, int b, int& x, int& y) {
  if (a < b) return extgcd(b, a, y, x);
  if (b > 0) {
    int g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  } else {
    x = 0, y = 1;
    return a;
  }
}

void solve(){
  int X;
  cin >> X;

  map<int,int> mp; int num = 2;
  REP(i,20) mp[num+1] = num, num *= 2;

  int cnt,Y,Z,K;
  FOR(j,1,1000000){
    if(mp.count(X)) j = mp[X];
    Y = X*j;
    Z = X^Y;
    FOR(k,1,100){
      if(__gcd(X*k,Z)==1){
        int u = 0, v = 0;
        int g = extgcd(X*k,Z,u,v);
        if(u%2 && X*k*u < Z*v) continue;
        if(v%2 && X*k*u > Z*v) continue;
        K = k; cnt = j;
        goto out;
      }
    }
  }
  out:;

  //debug(K);
  
  vec a,b,c;
  REP(i,20){
    a.push_back(X<<i);
    b.push_back(X<<i);
    c.push_back(0); //+
  }
 
  // 0
  a.push_back(X);
  b.push_back(X);
  c.push_back(1); // ^

  int now = 0;
  REP(i,20){
    if(parity(cnt,i)){
      a.push_back(X<<i);
      b.push_back(now);
      c.push_back(0); //+      
      now += (X<<i);
    }
  }

  // W
  now = 0;
  REP(i,20){
    if(parity(K,i)){
      a.push_back(X<<i);
      b.push_back(now);
      c.push_back(0); //+      
      now += (X<<i);
    }
  }

  // Z
  a.push_back(X);
  b.push_back(Y);
  c.push_back(1); // ^

  int W = X*K;
  //debug(Z);
  //debug(W);

  int u = 0, v = 0;
  int g = extgcd(W,Z,u,v);
  
  u = abs(u); v = abs(v);

  REP(i,60){
    if((W<<i) > (int)2e18) break;
    a.push_back(W<<i);
    b.push_back(W<<i);
    c.push_back(0); //+
  }

  REP(i,60){
    if((Z<<i) > (int)2e18) break;
    a.push_back(Z<<i);
    b.push_back(Z<<i);
    c.push_back(0); //+
  }
  
  now = 0;
  REP(i,60){
    if(parity(u,i)){
      a.push_back(W<<i);
      b.push_back(now);
      c.push_back(0); //+      
      now += (W<<i);
    }
  }

  now = 0;
  REP(i,60){
    if(parity(v,i)){
      a.push_back(Z<<i);
      b.push_back(now);
      c.push_back(0); //+      
      now += (Z<<i);
    }
  }

  a.push_back(W*u);
  b.push_back(Z*v);
  c.push_back(1); // ^

  cout << a.size() << endl;
  char d[] = {'+','^'}; 
  REP(i,a.size()){
    cout << a[i] SP d[c[i]] SP b[i] << endl;
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