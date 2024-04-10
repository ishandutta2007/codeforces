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
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef pair<int,int> P;
typedef vector<vector<P>> Graph;


void divisor(const int n, vector<int> &ret) {
  for(int i=1;i*i<=n;i++){
    if(n % i == 0) {
      ret.pb(i);
      if(i*i!= n) ret.pb(n/i);
    }
  }
  sort(ret.begin(),ret.end());
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  cin >> n;

  const int NMAX = 1e6 + 10;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<int> dp(NMAX,0);
  dp[0] = 1;

  REP(i,n){
    vector<int> tmp;
    divisor(a[i],tmp);
    RREP(j,tmp.size()){
      //debug(tmp[j]);
      dp[tmp[j]] += dp[tmp[j]-1];
      dp[tmp[j]] %= MOD;
    }
  }

  int ans = 0;
  REP(i,n){
    ans += dp[i+1];
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}