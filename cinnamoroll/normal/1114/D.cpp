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

  int n;
  cin >> n;

  vector<int> a(n),b;
  REP(i,n) cin >> a[i];
  
  a.erase(unique(a.begin(),a.end()),a.end());
  n = a.size();

  b = a;
  reverse(b.begin(),b.end());

  vector<int> dp[n+1];
  REP(i,n+1) dp[i].assign(n+1,0);

  REP(i,n){
    REP(j,n){
      if(a[i] == b[j]) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j])+1;
      else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
    }
  }

  int ans = INF;
  REP(i,n){
    ans = min(ans,n-dp[i][n-i-1]-1);
  }

  cout << ans << endl;

  return 0;
}