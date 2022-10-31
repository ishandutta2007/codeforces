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

  map<int,int> pos,neg;
  int zeroN = 0;
  REP(i,n){
    string s;
    cin >> s;
    int cnt = 0, mn = INF;
    bool posi = true;
    REP(j,s.size()){
      if(s[j] == '(') cnt++;
      else cnt--;
      if(cnt < 0) posi = false;
      mn = min(mn,cnt);
    }
    if(cnt > 0 && s[0] == '(' && posi) pos[cnt]++;
    if(cnt < 0 && s[s.size()-1] == ')' && mn == cnt) neg[cnt]++;
    if(cnt == 0 && posi) zeroN++;
  }

  int ans = 0;
  ITR(itr,neg){
    ans += min(pos[-itr->fs],itr->sc);
  }

  ans += zeroN/2;

  cout << ans << endl;

  return 0;
}