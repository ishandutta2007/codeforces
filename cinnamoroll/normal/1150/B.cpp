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

  int n;
  cin >> n;

  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int dx[] = {0,0,0,-1,1}, dy[] = {0,1,-1,0,0};
  FOR(i,1,n-1){
    FOR(j,1,n-1){
      bool flag = true;
      REP(k,5) if(s[i+dx[k]][j+dy[k]] == '#') flag = false;
      if(flag) REP(k,5) s[i+dx[k]][j+dy[k]] = '#';
    }
  }

  bool check = true;
  REP(i,n){
    REP(j,n){
      if(s[i][j] == '.') check = false;
    }
  }

  if(check) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}