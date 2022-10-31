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

const int N = 222;
vector<int> edge[N];
int n,k;
vector<int> a(N);
mat dp(222,vec(222,0));

void dfs(int no, int par=-1){
  for(int to: edge[no]){
    if(to==par) continue;
    dfs(to,no);
    vec tmp(222,-INF);
    REP(i,222) REP(j,222){
      if(i+j+1>k)tmp[min(i,j+1)] = max(tmp[min(i,j+1)],dp[no][i]+dp[to][j]);
    }
    REP(i,222) dp[no][i] = max(dp[no][i],tmp[i]);
  }
  dp[no][0] = max(dp[no][0],dp[no][k+1]+a[no]);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  
  REP(i,n) cin >> a[i];

  REP(_,n-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  dfs(0);

  int ans = 0;
  REP(i,222) ans = max(ans,dp[0][i]);

  cout << ans << endl;

  return 0;
}