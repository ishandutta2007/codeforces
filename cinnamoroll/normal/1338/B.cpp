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

const int N = 1e5+10;
vector<int> edge[N];
int mx, mn;

bool dfs(int no, int par){
  int cnt = 0;
  for(int to: edge[no]){
    if(to==par) continue;
    if(dfs(to,no)) cnt++;
  }
  mx -= max(0LL,cnt-1);
  return (edge[no].size()==1);
}

vec dist(N,0);
void dfs2(int no, int par = -1){
  for(int to: edge[no]){
    if(to==par) continue;
    dist[to] = dist[no]+1;
    dfs2(to,no);
  }
}
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  REP(_,n-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  int r; mx = n-1;
  REP(i,n) if(edge[i].size()>1) r = i;
  dfs(r,-1);
  dfs2(r);

  int e[2] = {};
  REP(i,n) if(edge[i].size()==1) e[dist[i]%2]++;

  if(!e[0]||!e[1]) mn = 1;
  else mn = 3;

  cout << mn SP mx << endl;

  return 0;
}