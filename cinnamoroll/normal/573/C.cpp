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
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<int> edge[101010],used(101010,0);
void dfs(int no, int par){
  if(used[no]) return;
  used[no]++;
  for(int to:edge[no]){
    if(to==par) continue;
    if(edge[to].size()<=2) dfs(to,no);
  }
}

void solve(){
  int N;
  cin >> N;

  REP(_,N-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  } 

  REP(i,N) if(edge[i].size()==1) dfs(i,-1);

  vec cnt(N,0);
  REP(i,N){
    for(int to:edge[i]){
      if(used[to]) cnt[i]++;
    }
  }

  REP(i,N){
    if(used[i]) continue;
    int tmp = 0;
    for(int to:edge[i]){
      if(!used[i] && edge[to].size()-min(2LL,cnt[to]) > 1) tmp++;
    }
    if(tmp > 2){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}