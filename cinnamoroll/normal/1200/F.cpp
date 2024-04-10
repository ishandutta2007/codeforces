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
//#define int long long
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
typedef vector<vector<P>> mat2;
 
int n;
const int N = 1010,NN = 2520;
mat2 edge(N,vector<P>(NN));
mat used(N,vec(NN,0)),ans(N,vec(NN,-1));
 
int dfs(int no, int d, set<int> &st){
  if(used[no][d] && ans[no][d] != -1) return ans[no][d];
  P to = edge[no][d];
  if(used[no][d] == 2) return ans[no][d] = st.size();
  used[no][d]++;
  if(used[no][d] == 2) st.insert(no);
  return ans[no][d] = dfs(to.fs,to.sc,st);
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  cin >> n;
 
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  REP(i,n){
    int m;
    cin >> m;
 
    vector<int> b(m);
    REP(j,m) cin >> b[j],b[j]--;
    
    REP(j,2520){
      int tmp = ((j+a[i])%2520+2520)%2520;
      edge[i][j].fs = b[tmp%m];
      edge[i][j].sc = tmp;
    }
  }
 
  REP(i,n) REP(j,2520){
    if(used[i][j]==0){
      set<int> st;
      ans[i][j] = dfs(i,j,st);
    }
  }
 
  int q;
  cin >> q;
 
  REP(_,q){
    int x,y;
    cin >> x >> y;
    cout << ans[x-1][(y%2520+2520)%2520] << "\n";
  }
 
  return 0;
}