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
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  cin >> n;

  vector<int> a(n),b(n);
  REP(i,n){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  
  vector<int> ans(n), used(n,0);
  ans[0] = 0;
  REP(i,n-2){
    int tmp = ans[i];
    if(a[a[tmp]] == b[tmp] || b[a[tmp]] == b[tmp]){
      ans[i+1] = a[tmp];
      used[a[tmp]]++;
    }
    else{
      ans[i+1] = b[tmp];
      used[b[tmp]]++;
    }
  }

  REP(i,n) if(used[i] == 0) ans[n-1] = i;

  REP(i,n) cout << ans[i]+1 << " ";

  return 0;
}