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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
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

  int n,x;
  cin >> n >> x;

  int mx = pow(2,n)-1;
  if(mx < x || x == 0){
    cout << mx << endl;
    REP(i,mx) cout << ((i+1)^i) << " ";
  }

  else{
    vec ans;
    int cur = 0;
    int bit;
    REP(i,n) if((1<<i)&x) bit = i;
    REP(i,mx/2)ans.push_back((i+1)^i);
    //debug(bit);
    cout << ans.size() << endl;
    REP(i,ans.size()) cout << ans[i]%(1<<bit) + ((ans[i]>>(bit))<<(bit+1)) << " ";
    cout << endl;
  }

  return 0;
}