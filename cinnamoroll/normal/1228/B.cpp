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
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
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

void ng(){
  cout << 0 << endl;
  exit(0);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h,w;
  cin >> h >> w;

  vector<int> a(h);
  REP(i,h) cin >> a[i];
  
  vector<int> b(w);
  REP(i,w) cin >> b[i];
  
  mat flag(h,vec(w,0));
  REP(i,h){
    REP(j,a[i]){
      if(flag[i][j]==-1) ng();
      flag[i][j] = 1;
    }
    if(a[i]!=w){
      if(flag[i][a[i]]==1) ng();
      flag[i][a[i]]=-1;
    }
  }

  REP(i,w){
    REP(j,b[i]){
      if(flag[j][i]==-1) ng();
      flag[j][i] = 1;
    }
    if(b[i]!=h){
      if(flag[b[i]][i] == 1) ng();
      flag[b[i]][i] = -1;
    }
  }

  int ans = 1;
  REP(i,h) REP(j,w) if(flag[i][j]==0) ans *= 2, ans %= MOD;

  cout << ans << endl;

  return 0;
}