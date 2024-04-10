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
#define INF (1LL<<60)
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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int N = 1e5+10;
vector<P> edge[N];
vec cost(N,0),used(N,0);

void dfs(int no){
  used[no]++;
  for(P to:edge[no]){
    cost[no] += to.sc;
    cost[to.fs] -= to.sc;
    if(!used[to.fs]) dfs(to.fs);
  }
}

using T = tuple<int,int,int>;
vector<T> ans;
void dfs2(int no, int r){
  if(cost[no]<0){
    int v = min(cost[r],-cost[no]);
    if(v) ans.push_back(T(r,no,v));
    cost[r] -= v; cost[no] += v;
  }
  if(used[no]) return;
    used[no]++;
  for(P to:edge[no]){
    dfs2(to.fs,r);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  REP(_,m){
    int x,y,d;
    cin >> x >> y >> d;
    edge[x-1].emplace_back(y-1,d);
  }

  REP(i,n){
    if(used[i]) continue;
    dfs(i);
  }

 // REP(i,n) cout << cost[i] << endl;

  vector<P> pos,neg;
  REP(i,n){
    if(cost[i]>0) pos.push_back(P(i,cost[i]));
    else if(cost[i]<0)  neg.push_back(P(i,-cost[i]));
  }

  while(pos.size()){
    int v = min(pos.back().sc,neg.back().sc);
    ans.push_back(T(pos.back().fs,neg.back().fs,v));
    pos.back().sc -= v;
    neg.back().sc -= v;
    if(pos.back().sc==0) pos.pop_back();
    if(neg.back().sc==0) neg.pop_back();
  }

  cout << ans.size() << endl;
  REP(i,ans.size()){
    int x,y,d;
    tie(x,y,d) = ans[i];
    cout << x+1 SP y+1 SP d << "\n";
  }

  return 0;
}