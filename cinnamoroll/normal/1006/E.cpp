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

const int N = 2e5+10;
vector<int> edge[N],a,b(N),sz(N,1);
int cnt = 0;

void dfs(int no, int par){
  a.push_back(no);
  b[no] = cnt;
  cnt++;
  for(int to: edge[no]){
    if(to==par) continue;
    dfs(to,no);
    sz[no] += sz[to];
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,q;
  cin >> n >> q;

  REP(i,n-1){
    int x;
    cin >> x;
    edge[i+1].push_back(x-1);
    edge[x-1].push_back(i+1);
  }

  dfs(0,-1);

  REP(_,q){
    int x,y;
    cin >> x >> y; x--;
    if(y <= sz[x]) cout << a[b[x]+y-1]+1 << "\n";
    else cout << -1 << "\n";
  }

  return 0;
}