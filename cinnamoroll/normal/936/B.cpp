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
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vec edge[100010];
mat dist(2,vec(100010,-1));
void dfs(int no, int d){
  for(int to:edge[no]){
    if(dist[d^1][to]==-1){
      dist[d^1][to] = no;
      dfs(to,d^1);
    }
  }
}

const int NMAX = 2e5+10;
vector<int> g[NMAX]; // g[i][j]-> ij
int h[NMAX]; //h[i]-> i
int v,e;

vector<int> t_sort(){
  stack<int> st;
  REP(i, v) if(h[i] == 0) st.push(i);
  vector<int> res;
  while(st.size()) {
    int i = st.top(); st.pop();
    res.push_back(i);
    for(auto& j: g[i]) {
      h[j]--;
      if(h[j] == 0) st.push(j);
    }
  }
  return res;
}
// v,e
// res.size()v

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  REP(i,n){
    int x; cin >> x;
    REP(_,x){
      int y; cin >> y; y--;
      edge[i].push_back(y);
    }
  }

  int s; cin >> s; s--;
  dist[0][s] = -2;
  dfs(s,0);

  //REP(i,n) cout << dist[0][i] SP dist[1][i] << endl;

  REP(i,n){
    if(edge[i].size()) continue;
    if(dist[1][i]!=-1){
      int no = i; cout << "Win" << endl;
      vec ans; int d = 1;
      while(no!=-2){
        ans.push_back(no);
        no = dist[d][no];
        d ^= 1;
      }
      RREP(i,ans.size()) cout << ans[i]+1 << " ";
      return 0;
    }
  }

  v = n;
  REP(i,n){
    if(dist[0][i]==-1&&dist[1][i]==-1) continue;
    REP(j,edge[i].size()) g[i].push_back(edge[i][j]), e++, h[edge[i][j]]++;
  }

  vec tmp = t_sort();
  //REP(i,tmp.size()) cout << tmp[i] << endl;

  if(tmp.size()!=v) cout << "Draw" << endl;
  else cout << "Lose" << endl;

  return 0;
}