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
vec edge[N],ans(N,0),a(N);
unordered_map<int,int> mp[N];

void dfs(int no, int par){
  ans[a[no]]++;
  mp[no][a[no]]++;
  for(int to:edge[no]){
    if(to == par) continue;
    dfs(to,no);
    ITR(i,mp[no]) ITR(j,mp[to]){
      int g = __gcd(i->fs,j->fs);
      ans[g] += i->sc*j->sc;
    }
    ITR(i,mp[to]) mp[no][__gcd(a[no],i->fs)] += i->sc;
    mp[to].clear();
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  REP(i,n) cin >> a[i];
  
  REP(_,n-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  dfs(0,-1);

  REP(i,N) if(ans[i]) cout << i SP ans[i] << "\n";

  return 0;
}