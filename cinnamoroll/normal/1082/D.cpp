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

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n){
    cin >> a[i];
  }
  
  int num = accumulate(a.begin(),a.end(),0LL);
  if(num < 2*(n-1)){
    cout << "NO" << endl;
    return 0;
  }

  int tmp = 0;
  vector<int> ok;
  vector<int> flag(n,0);
  
  REP(i,n){
    if(a[i] > 1){
      tmp++;
      ok.pb(i);
      flag[i]++;
    }
  }

  vector<P> ans;
  REP(i,tmp-1){
    ans.pb(P(ok[i],ok[i+1]));
    a[ok[i]]--;
    a[ok[i+1]]--;
  }

  int in = tmp-1;
  bool f = true;
  REP(i,n){
    if(flag[i]) continue;
    while(a[ok[in]] == 0) in++;
    ans.pb(P(i,ok[in]));
    a[ok[in]]--;
    if(f){
      in = 0;
      f = false;
    }
  }

  cout << "YES " << min(n-1,tmp+1) << endl;
  cout << ans.size() << endl;
  REP(i,ans.size()){
    cout << ans[i].fs+1 << " " << ans[i].sc+1 << endl;
  }

  return 0;
}