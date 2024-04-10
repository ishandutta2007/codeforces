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

int dp[2][3][202020];
void init(int N){
  REP(i,N+1) REP(j,2) REP(k,3) dp[j][k][i] = LINF;
}

void solve(){
  int N;
  string S;
  cin >> N >> S;

  init(N);
  int ans = LINF;
  // L
  int x = (S[0]=='L')+(S[1]=='R');
  dp[1][0][1] = 2-x;
  FOR(i,2,N){
    REP(j,2){
      if(S[i]=='L'){
        chmin(dp[0][j+1][i],dp[0][j][i-1]); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]+1); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]+1); // R=>R
      }
      else{
        chmin(dp[0][j+1][i],dp[0][j][i-1]+1); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]+1); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]); // R=>R
      }
    }
  }

  REP(i,2) REP(j,2) if(i!=0||j!=1) chmin(ans,dp[i][j][N-1]);
//debug(ans);
  init(N);
  x =  (S[0]=='R')+(S[1]=='L');
  dp[0][0][1] = 2-x;
  FOR(i,2,N){
    REP(j,2){
      if(S[i]=='L'){
        chmin(dp[0][j+1][i],dp[0][j][i-1]); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]+1); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]+1); // R=>R
      }
      else{
        chmin(dp[0][j+1][i],dp[0][j][i-1]+1); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]+1); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]); // R=>R
      }
    }
  }

  REP(i,2) REP(j,2) if(i!=1||j!=1) chmin(ans,dp[i][j][N-1]);
//debug(ans);
  init(N);
  x = (S[0]=='R')+(S[1]=='R');
  dp[1][1][1] = 2-x;
  FOR(i,2,N){
    REP(j,2){
      if(S[i]=='L'){
        chmin(dp[0][j+1][i],dp[0][j][i-1]); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]+1); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]+1); // R=>R
      }
      else{
        chmin(dp[0][j+1][i],dp[0][j][i-1]+1); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]+1); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]); // R=>R
      }
    }
  }

  REP(i,2) REP(j,2) if(i!=1) chmin(ans,dp[i][j][N-1]);
//debug(ans);
  init(N);
  x =  (S[0]=='L')+(S[1]=='L');
  dp[0][1][1] = 2-x;
  FOR(i,2,N){
    REP(j,2){
      if(S[i]=='L'){
        chmin(dp[0][j+1][i],dp[0][j][i-1]); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]+1); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]+1); // R=>R
      }
      else{
        chmin(dp[0][j+1][i],dp[0][j][i-1]+1); // L=>L
        chmin(dp[1][0][i],dp[0][j][i-1]); // L=>R
        chmin(dp[0][0][i],dp[1][j][i-1]+1); // R=>L
        chmin(dp[1][j+1][i],dp[1][j][i-1]); // R=>R
      }
    }
  }

  REP(i,2) REP(j,2) if(i!=0) chmin(ans,dp[i][j][N-1]);
  //debug(ans);
  cout << ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}