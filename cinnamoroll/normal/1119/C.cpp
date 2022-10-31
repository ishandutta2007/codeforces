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

  mat a(n,vec(m)),b(n,vec(m));

  REP(i,n) REP(j,m) cin >> a[i][j];
  REP(i,n) REP(j,m) cin >> b[i][j];

  mat tmp(n,vec(m,0));
  REP(i,n)REP(j,m) if(a[i][j] != b[i][j]) tmp[i][j]++;

  REP(i,n){
    int cnt = 0;
    REP(j,m) if(tmp[i][j]) cnt++;
    if(cnt%2){
      cout << "No" << endl;
      return 0;
    }
  }

  REP(j,m){
    int cnt = 0;
    REP(i,n) if(tmp[i][j]) cnt++;
    if(cnt%2){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}