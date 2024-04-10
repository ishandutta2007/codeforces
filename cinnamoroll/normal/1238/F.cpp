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

void dfs(int no, int par, mat &edge, mat &dp){
  int mx1 = 0, mx2 = 0;
  for(int to:edge[no]){
    if(to == par) continue;
    dfs(to,no,edge,dp);
    dp[no][0] = max(dp[no][0],dp[to][0]);
    if(mx1 <= dp[to][1]){
      mx2 = mx1; mx1 = dp[to][1];
    }
    else if(mx2 <= dp[to][1]){
      mx2 = dp[to][1];
    }
  }
  dp[no][0] = max(dp[no][0],mx1+mx2+(int)edge[no].size()+1);
  dp[no][1] = max(dp[no][1],mx1+(int)edge[no].size()-1);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n;
    cin >> n;

    mat edge(n);
    REP(_,n-1){
      int x,y;
      cin >> x >> y;
      x--; y--;
      edge[x].emplace_back(y);
      edge[y].emplace_back(x);
    }

    mat dp(n,vec(2,0));
    dfs(0,-1,edge,dp);

    cout << dp[0][0] << "\n";
  }

  return 0;
}