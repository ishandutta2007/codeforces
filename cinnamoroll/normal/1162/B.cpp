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

  int n,m;
  cin >> n >> m;

  vector<vector<int>> a(n,vector<int>(m));
  REP(i,n) REP(j,m) cin >> a[i][j];
  
  vector<vector<int>> b(n,vector<int>(m));
  REP(i,n) REP(j,m) cin >> b[i][j];
  
  REP(i,n){
    REP(j,m){
      if(a[i][j] > b[i][j]) swap(a[i][j],b[i][j]);
    }
  }

  REP(i,n) REP(j,m-1){
    if(a[i][j] >= a[i][j+1] || b[i][j] >= b[i][j+1]){
      cout << "Impossible" << endl;
      return 0;
    }
  }

  REP(i,n-1) REP(j,m){
    if(a[i][j] >= a[i+1][j] || b[i][j] >= b[i+1][j]){
      cout << "Impossible" << endl;
      return 0;
    }
  }

  cout << "Possible" << endl;

  return 0;
}