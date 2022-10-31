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

  int n,k;
  cin >> n >> k;

  vector<int> a(k);
  REP(i,k) cin >> a[i];

  vector<int> sum[n+1];

  REP(i,k){
    sum[a[i]].pb(i);
  }

  int mn = INF;
  FOR(i,1,n+1) mn = min(mn,(int)sum[i].size());

  vector<int> ans(k,0);
  REP(i,mn){
    int tmp = 0;
    FOR(j,1,n+1){
      tmp = max(tmp,sum[j][i]);
    }
    ans[tmp]++;
  }

  REP(i,k) cout << ans[i];

  return 0;
}