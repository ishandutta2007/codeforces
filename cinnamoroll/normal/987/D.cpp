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

int n,m,k,s;
const int N = 1e5;
mat cost(N,vec(100,-1));
vec edge[N],a(N);

void bfs(int x){
  queue<int> que;
  REP(i,n) if(a[i]==x) que.push(i), cost[i][x] = 0;
  while(que.size()){
    int no = que.front(); que.pop();
    for(int to:edge[no]){
      if(cost[to][x] != -1) continue;
      cost[to][x] = cost[no][x]+1;
      que.push(to);
    }
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k >> s;

  REP(i,n) cin >> a[i], a[i]--;
  
  REP(_,m){
    int x,y;
    cin >> x >> y; x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  REP(i,k) bfs(i);

  REP(i,n){
    cost[i].resize(k);
    sort(cost[i].begin(),cost[i].end());
    int ans = 0;
    REP(j,s) ans += cost[i][j];
    cout << ans << " ";
  }

  cout << endl;

  return 0;
}