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
  string t;
  cin >> n >> t;

  vector<int> a(n),s(n+1,0);
  int cnt = 0;
  REP(i,n){
    if(t[i] == '(') a[i] = 1;
    else a[i] = -1;
    cnt += a[i];
    s[i+1] += s[i]+a[i];
  }

  if(abs(cnt) != 2){
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  vector<int> mn(n+1,INF);
  RREP(i,n) mn[i] = min(mn[i+1],s[i+1]); 

  if(cnt == 2){
    REP(i,n){
      if(s[i] < 0) break;
      if(a[i] == 1 && mn[i] >= 2) ans++;
    }
  }

  else{

    REP(i,n){
      if(s[i] < 0) break;
      if(a[i] == -1 && mn[i] >= -2) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}