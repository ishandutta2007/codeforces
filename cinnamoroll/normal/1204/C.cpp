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

  vector<string> s(n);
  REP(i,n) cin >> s[i];
  
  int m;
  cin >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i], a[i]--;
  
  vector<int> dist[n];
  REP(i,n) dist[i].assign(n,INF);
  
  REP(i,n) dist[i][i] = 0;
  REP(i,n) REP(j,n) if(s[i][j] == '1') dist[i][j] = 1;
  
  REP(k,n){
    REP(i,n){
      REP(j,n){
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
      }
    }
  }

  vec ans;
  ans.push_back(a[0]);
  REP(i,m-1){
    FOR(j,i+1,m){
      if(dist[a[i]][a[j]] == j-i) continue;
      ans.push_back(a[j-1]);
      i = j-2;
      break;
    }
  }

  ans.push_back(a.back());

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i]+1 << " ";
  cout << endl;

  return 0;
}