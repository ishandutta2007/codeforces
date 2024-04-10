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

const int NMAX = 1e5;
int sx,sy,gx,gy,n;
string s;
vector<int> sum_x(NMAX,0),sum_y(NMAX,0);

bool check(int mid){
  int x = (mid/n)*sum_x[n] + sum_x[mid%n], y = (mid/n)*sum_y[n] + sum_y[mid%n];
  int tmpX = gx-sx, tmpY = gy - sy;
  int pos = abs(tmpX-x) + abs(tmpY-y);
  //debug(pos);
  //debug(mid);
  return pos <= mid;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //

  cin >> sx >> sy >> gx >> gy >> n >> s;

  REP(i,n){
    sum_x[i+1] = sum_x[i];
    sum_y[i+1] = sum_y[i];
    if(s[i] == 'U') sum_y[i+1]++;
    if(s[i] == 'D') sum_y[i+1]--;
    if(s[i] == 'L') sum_x[i+1]--;
    if(s[i] == 'R') sum_x[i+1]++;
  }

  int ng = -1, ok = 1e16;
  while (abs(ng-ok)>1) {
    int mid = (ng+ok)/2;
    (check(mid)?ok:ng) = mid;
  }

  if(ok == (int)1e16) cout << -1 << endl;
  else cout << ok << endl;

  return 0;
}