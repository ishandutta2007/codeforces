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

const int NMAX = 1e5;
vec edge[NMAX],res(NMAX),used(NMAX,0),ans(NMAX,0);

void dfs(int no){
  used[no]++;
  bool flag = true;
  for(int to:edge[no]){
    if(used[to]) continue;
    dfs(to);
    if(res[to] == 0) flag = false;
  }
  if(res[no] && flag) ans[no]++;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int root;
  REP(i,n){
    int x,y;
    cin >> x >> y;
    x--; y;
    if(x != -2) edge[x].push_back(i);
    else root = i;
    res[i] = y;
  }

  dfs(root);

  bool flag = true;
  REP(i,n) if(ans[i]) cout << i+1 << " ", flag = false;
  if(flag) cout << -1; 

  return 0;
}