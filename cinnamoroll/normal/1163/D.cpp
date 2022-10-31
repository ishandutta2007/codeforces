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
//#define MOD 998244353
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
typedef pair<P,P> PP;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int nx[55][2][26];
void calc(int len, string s, int id){
  REP(i,len+1){
    for(char ch = 'a'; ch <= 'z'; ch++){
      string t = s.substr(0,i) + ch;
      int cnt = t.size();
      //
      while(cnt && t.substr(t.size()-cnt,cnt) != s.substr(0,cnt)) cnt--;
      nx[i][id][ch-'a'] = cnt;
    }
  }
}


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s,t,c;
  cin >> c >> s >> t;

  int x = c.size(), y = s.size(), z = t.size();

  int dp[x+1][y+1][z+1];
  REP(i,x+1) REP(j,y+1) REP(k,z+1) dp[i][j][k] = -INF;
  dp[0][0][0] = 0;

  //
  calc(y,s,0);
  calc(z,t,1);

  REP(i,x){
    REP(j,y+1){
      REP(k,z+1){
        if(dp[i][j][k] < -1e7) continue;
        for(char ch = 'a'; ch <= 'z'; ch++){
          if(c[i] != '*' && c[i] != ch) continue;
          int tmp = dp[i][j][k];
          int nx_s = nx[j][0][ch-'a'], nx_t = nx[k][1][ch-'a'];
          if(nx_s == y) tmp++;
          if(nx_t == z) tmp--;
          dp[i+1][nx_s][nx_t] = max(dp[i+1][nx_s][nx_t],tmp);
        }
      }
    }
  }

  int ans = -INF;
  REP(i,y+1) REP(j,z+1) ans = max(dp[x][i][j],ans);

  cout << ans << endl;

  return 0;
}