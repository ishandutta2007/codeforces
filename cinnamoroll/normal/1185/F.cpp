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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<int> a(1<<9,0);
  REP(i,n){
    int x,v = 0;
    cin >> x;
    REP(_,x){
      int k;
      cin >> k;
      k--;
      v |= 1<<k;
    }
    a[v]++;
  }

  mat b(1<<9,vec(2,INF)), in(1<<9,vec(2,-1));
  REP(j,m){
    int x,y,v = 0;
    cin >> x >> y;
    REP(i,y){
      int k;
      cin >> k;
      k--;
      v |= 1<<k;
    }
    if(b[v][0] > x){
      b[v][1] = b[v][0];
      b[v][0] = x;
      in[v][1] = in[v][0];
      in[v][0] = j+1;
    }
    else if(b[v][1] > x) b[v][1] = x, in[v][1] = j+1;
  }

  P ans, mx = P(-INF,INF);
  REP(i,1<<9){
    FOR(j,i,1<<9){
      int x = b[i][0], y = i==j?b[j][1]:b[j][0];
      int id1 = in[i][0], id2 = i==j?in[j][1]:in[j][0];
      if(x == INF || y == INF) continue;
      P cur = P(0,-x-y);
      int tmp = i | j;
      REP(k,1<<9) if((tmp & k) == k) cur.fs += a[k];
      if(mx < cur) mx = cur, ans = P(id1,id2);
      //debug(cur.fs);
    }
  }

  cout << ans.fs SP ans.sc << endl;

  return 0;
}