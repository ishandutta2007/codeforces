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
#define MOD 998244353
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
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<int> sum(n+1,0);
  priority_queue<P> que;
  REP(i,n){
    que.push(P(a[i],i));
  }

  P tmp; 
  REP(i,n-1){
    tmp = que.top();
    que.pop();
    if(tmp.fs == que.top().fs){
      sum[tmp.sc+1]--;
      sum[que.top().sc+1]++;
    }
  }

  REP(i,n) sum[i+1] += sum[i];
  //REP(i,n+1) cout << sum[i] << " ";
  //cout << endl;

  int ans = 1;
  FOR(i,1,n){
    if(sum[i] == 0) ans *= 2;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}