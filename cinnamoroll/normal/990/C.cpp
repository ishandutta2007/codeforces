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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> s(n);
  REP(i,n) cin >> s[i];
  
  map<int,int> mp;

  REP(i,n){
    int cnt = 0; bool flag = true;
    REP(j,s[i].size()) cnt += (s[i][j]=='('?1:-1);
    if(cnt>=0){
      cnt = 0;
      REP(j,s[i].size()){
        cnt += (s[i][j]=='('?1:-1);
        if(cnt < 0) flag = false;
      }
      if(flag) mp[cnt]++;
    }
    else{
      cnt = 0;
      RREP(j,s[i].size()){
        cnt += (s[i][j]=='('?1:-1);
        if(cnt > 0) flag = false;
      }
      if(flag) mp[cnt]++;      
    }
  }

  int ans = 0;
  ITR(itr,mp){
    if(itr->fs < 0) continue;
    if(mp.count(-itr->fs)) ans += itr->sc*mp[-itr->fs];
  }

  cout << ans << endl;

  return 0;
}