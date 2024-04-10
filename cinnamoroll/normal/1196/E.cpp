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

  int q;
  cin >> q;

  REP(_,q){
    int b,w;
    cin >> b >> w;

    if(min(b,w)*3+1 < max(b,w)) cout << "NO" << "\n";
    else{
      cout << "YES" << "\n";
      if(w<b){
        REP(i,w*2) cout << 2 SP i+1 << "\n";
        int cnt = b-w;
        REP(i,w){
          if(cnt) cout << 1 SP 2*i+2 << "\n", cnt--;
          if(cnt) cout << 3 SP 2*i+2 << "\n", cnt--;
        }
        if(cnt) cout << 2 SP 2*w+1 << "\n", cnt--;
      }

      else{
        REP(i,b*2) cout << 2 SP i+2 << "\n";
        int cnt = w-b;
        REP(i,b){
          if(cnt) cout << 1 SP 2*i+3 << "\n", cnt--;
          if(cnt) cout << 3 SP 2*i+3 << "\n", cnt--;
        }
        if(cnt) cout << 2 SP 2*b+2 << "\n", cnt--;        
      }
    }
  }

  return 0;
}