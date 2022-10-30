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
#define D double
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

const int N = 2e5+10;
vec edge[N],used(N,0),sum;
int ans,now;

int dfs(int no){
  used[no]++;
  for(int to:edge[no]){
    if(used[to]) continue;
    sum[no] += dfs(to);
  }
  return sum[no];
}

void dfs2(int no){
  used[no]++;
  for(int to:edge[no]){
    if(used[to]) continue;
    now -= sum[to];
    sum[no] -= sum[to];
    now += sum[no];
    sum[to] += sum[no];
    dfs2(to);
    now -= sum[no];
    sum[to] -= sum[no];
    now += sum[to];
    sum[no] += sum[to];
  }
  ans = max(ans,now);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  sum.assign(n,1);

  REP(_,n-1){
    int x,y;
    cin >> x >> y; x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  dfs(0);

  ans = now = accumulate(sum.begin(),sum.end(),0LL);

  used.assign(n,0);

  dfs2(0);

  cout << ans << endl;

  return 0;
}