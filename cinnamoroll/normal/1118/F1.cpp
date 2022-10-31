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

const int NMAX = 3e5;
vector<int> edge[NMAX],a(NMAX),dist(NMAX,INF),r(NMAX,0),b(NMAX,0),visited(NMAX,0);

void dfs(int no){
  for(int to: edge[no]){
    if(dist[to] == INF){
      dist[to] = dist[no]+1;
      dfs(to);
    }
  }
}

void dfs2(int no){
  visited[no]++;
  for(int to: edge[no]){
    if(visited[to]) continue;
    dfs2(to);
    r[no] += r[to];
    b[no] += b[to];
  }
  if(a[no] == 1) r[no]++;
  if(a[no] == 2) b[no]++;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //

  int n;
  cin >> n;

  REP(i,n) cin >> a[i];
  int r_cnt = 0, b_cnt = 0;
  REP(i,n){
    if(a[i] == 1) r_cnt++;
    if(a[i] == 2) b_cnt++;
  }

  vector<int> X(n-1),Y(n-1);
  REP(i,n-1){
    int x,y;
    cin >> x >> y;
    edge[x-1].push_back(y-1);
    edge[y-1].push_back(x-1);
    X[i] = x-1, Y[i] = y-1;
  }

  dist[0] = 0;
  dfs(0);
  dfs2(0);

  int ans = 0;
  REP(i,n-1){
    int tmp;
    if(dist[X[i]] > dist[Y[i]]) tmp = X[i];
    else tmp = Y[i];
    if(r[tmp] == r_cnt && b[tmp] == 0) ans++;
    if(r[tmp] == 0 && b[tmp] == b_cnt) ans++;
  }

  cout << ans << endl;

  return 0;
}