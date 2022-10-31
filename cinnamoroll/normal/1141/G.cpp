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

const int NMAX = 2e5;
vec edge[NMAX], used(NMAX,0), d(NMAX,0);

void dfs(int no){
  int cnt = 0;
  used[no]++;
  for(int to:edge[no]){
    cnt++;
    if(used[to]) continue;
    dfs(to);
  }
  d[no] = cnt;
}


map<P,int> mp;
vec ans(NMAX,-1);
void dfs2(int no, int c, int r){
  int cnt = 0;
  for(int to:edge[no]){
    int id = mp[P(no,to)];
    if(ans[id] != -1) continue;
    ans[id] = (c+cnt)%r+1;
    cnt++;
    dfs2(to,c+cnt,r);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  vec x(n),y(n);
  REP(i,n-1){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
    edge[x[i]].push_back(y[i]);
    edge[y[i]].push_back(x[i]);
    mp[P(x[i],y[i])] = mp[P(y[i],x[i])] = i;
  }

  dfs(0);

  vec cnt(n+1,0);
  REP(i,n) cnt[d[i]]++;

  int sum = 0, r;
  RFOR(i,1,n+1){
    r = i;
    sum += cnt[i];
    if(sum > k) break;
  }

  cout << r << endl;
  dfs2(0,0,r);

  REP(i,n-1) cout << ans[i] << " ";

  return 0;
}