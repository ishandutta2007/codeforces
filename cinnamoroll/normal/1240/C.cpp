
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
typedef vector<vector<P>> mat;

int n,k;
auto comp = [](P a, P b){return a.fs-a.sc>b.fs-b.sc;};

P dfs(int no, int par, mat &edge){
  vector<P> cur;
  for(P to: edge[no]){
    if(to.fs==par) continue;
    P tmp = dfs(to.fs,no,edge);
    tmp.fs += to.sc;
    cur.emplace_back(tmp);
  }
  sort(cur.begin(),cur.end(),comp);
  int res1 = 0, res2 = 0;
  REP(i,cur.size()){
    res1 += i<k-1?max(cur[i].fs,cur[i].sc):cur[i].sc;
    res2 += i<k?max(cur[i].fs,cur[i].sc):cur[i].sc;
  }
  return P(res1,res2);
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int q;
  cin >> q;
 
  using T = tuple<int,int,int>;
 
  REP(i,q){
    cin >> n >> k;
    mat edge(n);
    REP(_,n-1){
      int x,y,c;
      cin >> x >> y >> c;
      x--; y--;
      edge[x].emplace_back(y,c);
      edge[y].emplace_back(x,c);
    }
    cout << dfs(0,-1,edge).sc << "\n";
  }
 
  return 0;
}