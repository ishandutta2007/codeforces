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
const double EPS = 1e-9;
#define INF (1LL<<60)
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
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  REP(_,t){
    int n;
    cin >> n;

    int mx = 0;
    int cur = 1;
    REP(i,9){
      vec tmp(n,0);
      int cnt = 0;
      REP(i,n) if((i+1)/cur%2) tmp[i] = 1, cnt++;
      if(cnt == 0 || cnt == n) break;
      cout << cnt SP n-cnt << " ";
      REP(i,n) if(tmp[i]) cout << i+1 << " ";
      REP(i,n) if(tmp[i] == 0) cout << i+1 << " ";
      cout << endl; cout.flush();
      int x;
      cin >> x;
      mx = max(mx,x);
      cur*=2;
    }
    cout << -1 SP mx << endl;
  }

  return 0;
}