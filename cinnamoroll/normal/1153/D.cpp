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

const int NMAX = 3e5;
vec a(NMAX),b(NMAX),used(NMAX,0);
vec edge[NMAX];
int dfs(int no){
  used[no]++;
  int sum = 0, mn = INF;
  bool flag = true;
  for(int to:edge[no]){
    if(used[to]) continue;
    flag = false;
    int tmp = dfs(to);
    sum += tmp;
    mn = min(mn,tmp);
  }
  if(flag) return 1;
  if(a[no] == 1) return mn;
  else return sum;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  //vec a(n);
  REP(i,n) cin >> a[i];

  //vec b(n-1);
  REP(i,n-1) cin >> b[i], b[i]--, edge[b[i]].push_back(i+1);
  
  vec flag(n,0);
  REP(i,n-1) flag[b[i]]++;

  int cnt = 0;
  REP(i,n) if(!flag[i]) cnt++;

  cout << cnt+1-dfs(0) << endl;

  return 0;
}