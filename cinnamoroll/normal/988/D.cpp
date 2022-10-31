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

  set<int> st;
  vector<int> a(n);
  REP(i,n){
    cin >> a[i];
    st.insert(a[i]);
  }

  bool flag = false;
  P ans;

  REP(i,n){
    int cnt = 1;
    while(a[i]+cnt <= (int)1e9){
      if(st.find(a[i]+cnt)!=st.end() && st.find(a[i]+cnt*2)!=st.end()){
        cout << 3 << endl;
        cout << a[i] SP a[i]+cnt SP a[i]+cnt*2 << endl;
        return 0;
      }
      if(!flag && st.find(a[i]+cnt)!=st.end()){
        flag = true;
        ans = P(a[i],a[i]+cnt);
      }
      cnt *= 2;
    }
  }

  if(flag) cout << 2 << endl << ans.fs SP ans.sc << endl;
  else cout << 1 << endl << a[0] << endl;

  return 0;
}