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
  //
  //
  //DP

  int n;
  string s,t;
  cin >> n >> s >> t;

  int cnt = 0;
  vec id[3];
  REP(i,n){
    if(t[i] == '1') cnt++;
    if(s[i] == '0' && t[i] == '0') id[0].push_back(i+1);
    else if(s[i] == '1' && t[i] == '1') id[2].push_back(i+1);
    else id[1].push_back(i+1);
  }

  int m = n/2;
  //0 1 2
  REP(i,m+1){
    REP(j,m+1){
      int k = m-i-j;
      if(k < 0) continue;
      if(id[0].size() < i || id[1].size() < j || id[2].size() < k) continue;
      if(j+2*k != cnt) continue;
      REP(x,i) cout << id[0][x] << " ";
      REP(x,j) cout << id[1][x] << " ";
      REP(x,k) cout << id[2][x] << " ";
      exit(0);
    }
  }
  
  cout << -1 << endl;

  return 0;
}