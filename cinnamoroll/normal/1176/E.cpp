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
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int N = 2e5+10;
vec edge[N], used, color;

void dfs(int no, int dist){
  used[no]++;
  color[no] = dist&1;
  for(int to: edge[no]){
    if(used[to]) continue;
    dfs(to,dist+1);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n,m;
    cin >> n >> m;

    REP(_,m){
      int x,y;
      cin >> x >> y;
      x--; y--;
      edge[x].emplace_back(y);
      edge[y].emplace_back(x);
    }

    used.assign(n,0);
    color.assign(n,-1);

    dfs(0,0);
    vec ans[2];
    REP(i,n) ans[color[i]].emplace_back(i+1);

    if(ans[0].size() <= ans[1].size()){
      cout << ans[0].size() << endl;
      REP(i,ans[0].size()) cout << ans[0][i] << " ";
      cout << endl;
    }
    else{
      cout << ans[1].size() << endl;
      REP(i,ans[1].size()) cout << ans[1][i] << " ";
      cout << endl;
    }

    REP(i,n) edge[i].clear();
  }

  return 0;
}