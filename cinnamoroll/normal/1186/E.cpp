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

int h,w,q;
mat sum(2222,vec(2222,0));
int calc(int x, int y){
  int res = 0;
  res += x/(2*h)*2*h*y;
  res += y/(2*w)*2*w*x;
  res -= (x/(2*h)*2*h)*(y/(2*w)*2*w);
  res /= 2;

  //debug(res);

  int s = 0, t = 0;
  int now = 1, step = x/(2*h)*2+1;
  while(now*2 <= step) now *= 2;
  while(step != 1){
    if(now < step){
      step -= now; s++;
    }
    now /= 2;
  }

  now = 1, step = y/(2*w)*2+1;
  while(now*2 <= step) now *= 2;
  while(step != 1){
    if(now < step){
      step -= now; t++;
    }
    now /= 2;
  }

  x %= 2*h; y %= 2*w;
  if(x == 0 || y == 0) return res;

  if(s%2 == t%2) res += sum[x-1][y-1];
  else res += x*y-sum[x-1][y-1];

  return res;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w >> q;

  vector<string> s(h);
  REP(i,h) cin >> s[i];

  REP(i,h) REP(j,w){
    if(s[i][j] == '1'){
      sum[i][j]++;
      sum[i+h][j+w]++;
    }
    else{
      sum[i][j+w]++;
      sum[i+h][j]++;
    }
  }

  REP(i,2*h) REP(j,2*w) sum[i+1][j] += sum[i][j];
  REP(i,2*h) REP(j,2*w) sum[i][j+1] += sum[i][j];
  
  REP(_,q){
    int u,v,x,y;
    cin >> u >> v >> x >> y; u--; v--;

    int ans = 0;
    ans += calc(x,y);
    //debug(ans);
    ans += calc(u,v);
    //debug(ans);
    ans -= calc(x,v);
    //debug(ans);
    ans -= calc(u,y);
    //debug(ans);

    cout << ans << '\n';
  }

  return 0;
}