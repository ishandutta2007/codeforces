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
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,q;
  string s;
  cin >> n >> q >> s;

  int dp[255][255][255];// i,j,k
  REP(i,255) REP(j,255) REP(k,255) dp[i][j][k] = INF;
  dp[0][0][0] = 0;

  mat next(26,vec(n+1,INF)); //icindex
  REP(i,26){
    RREP(j,n){
      next[i][j] = next[i][j+1];
      if(s[j]-'a' == i) next[i][j] = j;
    }
  }

  vector<string> str(3);
  vec len(3,0);
  REP(_,q){
    char c;
    int k;
    cin >> c >> k;
    k--;
    if(c == '+'){
      cin >> c;
      str[k] += c;
      len[k]++;
      int x = len[k];
      if(k == 0){
        REP(i,len[1]+1){
          REP(j,len[2]+1){
            dp[x][i][j] = INF;
            if(x > 0 && dp[x-1][i][j] != INF) dp[x][i][j] = min(dp[x][i][j],next[str[0][x-1]-'a'][dp[x-1][i][j]]+1);
            if(i > 0 && dp[x][i-1][j] != INF) dp[x][i][j] = min(dp[x][i][j],next[str[1][i-1]-'a'][dp[x][i-1][j]]+1);
            if(j > 0 && dp[x][i][j-1] != INF) dp[x][i][j] = min(dp[x][i][j],next[str[2][j-1]-'a'][dp[x][i][j-1]]+1);
          }
        }
      }
      if(k == 1){
        REP(i,len[0]+1){
          REP(j,len[2]+1){
            dp[i][x][j] = INF;
            if(x > 0 && dp[i][x-1][j] != INF) dp[i][x][j] = min(dp[i][x][j],next[str[1][x-1]-'a'][dp[i][x-1][j]]+1);
            if(i > 0 && dp[i-1][x][j] != INF) dp[i][x][j] = min(dp[i][x][j],next[str[0][i-1]-'a'][dp[i-1][x][j]]+1);
            if(j > 0 && dp[i][x][j-1] != INF) dp[i][x][j] = min(dp[i][x][j],next[str[2][j-1]-'a'][dp[i][x][j-1]]+1);
          }
        }
      }
      if(k == 2){
        REP(i,len[0]+1){
          REP(j,len[1]+1){
            dp[i][j][x] = INF;
            if(x > 0 && dp[i][j][x-1] != INF) dp[i][j][x] = min(dp[i][j][x],next[str[2][x-1]-'a'][dp[i][j][x-1]]+1);
            if(i > 0 && dp[i-1][j][x] != INF) dp[i][j][x] = min(dp[i][j][x],next[str[0][i-1]-'a'][dp[i-1][j][x]]+1);
            if(j > 0 && dp[i][j-1][x] != INF) dp[i][j][x] = min(dp[i][j][x],next[str[1][j-1]-'a'][dp[i][j-1][x]]+1);
          }
        }
      }
    }
    else{
      str[k].pop_back();
      len[k]--;
    }

    if(dp[len[0]][len[1]][len[2]] == INF) cout << "NO" << endl;
    else cout << "YES" << endl;
  }

  return 0;
}