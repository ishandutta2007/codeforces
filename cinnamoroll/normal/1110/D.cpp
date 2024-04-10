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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<int> sum(m+1,0);
  REP(i,n) sum[a[i]]++;

  int dp[m+1][3][3] = {};

  FOR(i,1,m+1){
    REP(x,3){
      REP(y,3){
        REP(z,3){
          if(sum[i] >= x+y+z){
            dp[i][y][z] = max(dp[i][y][z],dp[i-1][x][y]+z+(sum[i]-x-y-z)/3);
          }
        }
      }
    }
  }

  // 1()
  cout << dp[m][0][0] << endl;

  return 0;
}