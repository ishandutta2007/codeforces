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

void ng(){
  cout << -1 << endl;
  exit(0);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;
  
  int f = 0,fcnt = 0, b = 0, bcnt = 0;
  REP(i,n/2){
    if(s[i]!='?') f += s[i]-'0'; 
    else fcnt++;
    if(s[n-1-i]!='?') b += s[n-1-i]-'0';
    else bcnt++;
  }

  bool flag = true;
  if(f+(fcnt+1)/2*9 > b+(bcnt+1)/2*9) flag = false;
  if(b+(bcnt+1)/2*9 > f+(fcnt+1)/2*9) flag = false;

  if(flag) cout << "Bicarp" << endl;
  else cout << "Monocarp" << endl;

  return 0;
}