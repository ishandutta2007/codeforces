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
typedef vector<vector<int>> mat;

vector<string> s(50);
int memo[51][51][51][51];
int h[51][51], w[51][51];

int dfs(int lx,int ly,int rx,int ry){
  if(rx-lx==0 || ry-ly == 0) return 0;
  if(memo[lx][ly][rx][ry] != -1) return memo[lx][ly][rx][ry];

  int res = max(ry-ly,rx-lx);

  FOR(i,lx,rx) if(h[i][ly]==h[i][ry]) res = min(res,dfs(lx,ly,i,ry)+dfs(i+1,ly,rx,ry));
  FOR(i,ly,ry) if(w[lx][i]==w[rx][i]) res = min(res,dfs(lx,ly,rx,i)+dfs(lx,i+1,rx,ry));

  return memo[lx][ly][rx][ry] = res;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  REP(i,n) cin >> s[i];

  REP(i,51) REP(j,51) REP(k,51) REP(l,51) memo[i][j][k][l] = -1;

  REP(i,n) REP(j,n) h[i][j+1] = w[i+1][j] = (s[i][j]=='#');

  REP(i,n) REP(j,n){
    h[i][j+1] += h[i][j];
    w[i+1][j] += w[i][j];
  }

  cout << dfs(0,0,n,n) << endl;

  return 0;
}