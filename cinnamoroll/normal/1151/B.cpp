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

  int n,m;
  cin >> n >> m;

  mat a(n,vec(m));
  REP(i,n) REP(j,m) cin >> a[i][j];

  int id = -1;
  REP(i,n){
    REP(j,m-1) if(a[i][j] != a[i][j+1]) id = i;
  }

  if(id == -1){
    int tmp = 0;
    REP(i,n) tmp ^= a[i][0];
    if(tmp){
      cout << "TAK" << endl;
      REP(i,n) cout << 1 << " ";
      cout << endl;
    }
    else cout << "NIE" << endl;
    return 0;
  }

  int tmp = 0;
  REP(i,n){
    if(i != id) tmp ^= a[i][0];
  }

  REP(i,m){
    if(tmp == a[id][i]) continue;
    cout << "TAK" << endl;
    REP(j,n){  
      if(j != id) cout << 1 << " ";
      else cout << i+1 << " ";
    }return 0;
  }

  return 0;
}