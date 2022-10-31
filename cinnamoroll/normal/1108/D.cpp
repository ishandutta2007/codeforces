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
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  string s;
  cin >> n >> s;

  int dp[n+1][3] = {};
  char tmp[] = {'R','G','B'};
  REP(i,n){
    REP(j,3){
      if(s[i] == tmp[j]) dp[i+1][j] = min(dp[i][(j+1)%3],dp[i][(j+2)%3]);
      else dp[i+1][j] = min(dp[i][(j+1)%3],dp[i][(j+2)%3])+1;
    }
  }

  string ans;
  REP(i,n){
    int cnt = INF, id = -1;
    REP(j,3){
      if(tmp[j] == ans[ans.size()-1]) continue;
      if(cnt > dp[n-i][j]){
        cnt = dp[n-i][j];
        id = j;
      }
    }
    ans += tmp[id];
  }
  reverse(ans.begin(),ans.end());

  cout << min({dp[n][0],dp[n][1],dp[n][2]}) << endl << ans << endl;

  return 0;
}