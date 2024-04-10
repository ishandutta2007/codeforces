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

vec a(1<<22,0),b,used(1<<22,0);
int n,m;

void dfs(int x){
  if(used[x]) return;
  used[x]++;
  if(a[x]){
    a[x]--;
    b.emplace_back(x);
  }
  REP(i,n) if(x&(1<<i)) dfs(x^(1<<i));
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;

  REP(_,m){
    int x;
    cin >> x;
    a[x]++;
  }

  int ans = 0;
  REP(i,1<<n){
    if(a[i]){
      a[i]--;
      ans++;
      b.emplace_back(i);
      while(b.size()){
        int x = b.back(); b.pop_back();
        dfs(x^((1<<n)-1));
      }
    }
  }

  cout << ans << endl;

  return 0;
}