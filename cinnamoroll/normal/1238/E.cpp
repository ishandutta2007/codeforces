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
#define INF (1LL<<30)
#define D double
#define fs first
#define sc second
//#define int long long
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

  int n,m;
  string s;
  cin >> n >> m >> s;

  mat sum(m,vec(m,0));
  REP(i,n-1){
    sum[s[i]-'a'][s[i+1]-'a']++;
    sum[s[i+1]-'a'][s[i]-'a']++;
  }

  vec cost(1<<m,0);
  REP(i,1<<m){
    REP(j,m){
      if(i&(1<<j)) continue;
      cost[i|(1<<j)] = cost[i];
      REP(k,m){
        if(j==k) continue;
        if(i&(1<<k)) cost[i|(1<<j)] -= sum[j][k];
        else cost[i|(1<<j)] += sum[j][k];
      }
    }
  }

  vec dp(1<<m,INF);
  dp[0] = 0;

  REP(i,1<<m){
    REP(j,m){
      if(i&(1<<j)) continue;
      dp[i|(1<<j)] = min(dp[i|(1<<j)],dp[i]+cost[i]);
    }
  }

  cout << dp[(1<<m)-1] << endl;

  return 0;
}