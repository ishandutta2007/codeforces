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
#define INF 1LL<<50
#define fst first
#define sec second
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

  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> b;
  int cnt = 0;
  REP(i,m){
    int x,y,z;
    cin >> x >> y >> z;
    if(x != 1) continue;
    b.pb(y);
    if(y == 1000000000) cnt++;
  }

  if(n == 0){
    cout << cnt<< endl;
    return 0;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int sum[n+1] = {}; //
  int tmp = 0;
  REP(i,b.size()){
    while(b[i] >= a[tmp] && tmp<n){
      sum[tmp+1] = sum[tmp];
      tmp++;
    }
    if(b[i] < a[tmp])sum[tmp]++;
  }

  while(tmp < n){
    sum[tmp+1] = sum[tmp];
    tmp++;
  }

  sum[n] = b.size()-cnt;

 // REP(i,n+1) cout << sum[i] << endl;

  int ans = b.size();
  REP(i,n+1){
    ans = min(ans,b.size()-sum[i]+i);
  }

  cout << ans << endl;

  return 0;
}