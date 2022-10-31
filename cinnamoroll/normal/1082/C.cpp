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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,m;
  cin >> n >> m;

  vector<int> a[m];
  REP(i,n){
    int x,y;
    cin >> x >> y;
    x--;
    a[x].pb(y);
  }

  REP(i,m){
    sort(a[i].begin(),a[i].end());
    reverse(a[i].begin(),a[i].end());
  }

  REP(i,m){
    if(a[i].size() != 0)
    REP(j,a[i].size()-1){
      a[i][j+1] += a[i][j];
    }
  }
  
  vector<int> tmp(n+1,0);
  REP(i,m){
    REP(j,a[i].size()){
      if(a[i][j] > 0){
        tmp[j] += a[i][j]; //
      }
    }
  }

 // REP(i,m) tmp[a[i].size()] -= sum[i];

  int cnt = 0, ans = 0;
  REP(i,n+1){
    //debug(tmp[i]);
    //cnt += tmp[i];
    ans = max(ans,tmp[i]);
  }

  cout << ans << endl;

  return 0;
}