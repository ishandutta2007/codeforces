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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h,k;
  cin >> h >> k;

  int w = h;

  vector<string> s(h);
  REP(i,h) cin >> s[i];
  
  mat H(h+1,vec(w+1,0)), W(h+1,vec(w+1,0));
  vec hh(h+1,0), ww(h+1,0);
  REP(i,h){
    int l = -1, r = 0;
    REP(j,w){
      if(s[i][j] == 'B'){
        if(l == -1) l = j;
        r = j;
      }
    }
    REP(j,w){
      if(l == -1) H[i+1][j+1]++;
      else{
        if(j <= l && r-j+1 <= k) H[i+1][j+1]++;
      }
    }
    if(l == -1){
      hh[0]++, hh[max(1LL,(i+1)-k+1)]--;
      if(i+2<=h)hh[i+2]++;
    }
  }

  // REP(i,h){
  //   REP(j,h) cout << H[i+1][j+1];
  //   cout << endl;
  // }

  REP(j,w){
    int l = -1, r = 0;
    REP(i,h){
      if(s[i][j] == 'B'){
        if(l == -1) l = i;
        r = i;
      }
    }
    REP(i,h){
      if(l == -1) W[i+1][j+1]++;
      else{
        if(i <= l && r-i+1 <= k) W[i+1][j+1]++;
      }
    }
    if(l == -1){
      ww[0]++, ww[max(1LL,(j+1)-k+1)]--;
      if(j+2<=h)ww[j+2]++;
    }
  }

  // REP(i,h){
  //   REP(j,h) cout << W[i+1][j+1];
  //   cout << endl;
  // }

  REP(i,h+1) REP(j,w) {W[i][j+1] += W[i][j];}
  REP(i,h) REP(j,w+1) {H[i+1][j] += H[i][j];}
  REP(i,h) hh[i+1] += hh[i], ww[i+1] += ww[i];

  //REP(i,h+1) cout << hh[i] SP ww[i] << endl;

  int ans = 0;
  REP(i,h-k+1) REP(j,w-k+1){
    int tmp = H[i+k][j+1]-H[i][j+1] + W[i+1][j+k]-W[i+1][j];
    ans = max(ans,tmp+hh[i+1]+ww[j+1]);
  }

  cout << ans << endl;

  return 0;
}