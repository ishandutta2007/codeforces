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
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n,m,k;
  cin >> n >> m >> k;
 
  set<int> h[n+10],w[m+10];
  REP(_,k){
    int x,y;
    cin >> x >> y;
    h[x].insert(y);
    w[y].insert(x);
  }
  REP(i,n+10) h[i].insert(m+1),h[i].insert(0);
  REP(i,m+10) w[i].insert(n+1),w[i].insert(0);
 
  int sum = 0, l = 0, r = m+1, u = 1, d = n+1;
  int nowH = 1, nowW = 1; 
  int state = 0;
  int pre = -1;
  while(1){
    int cur;
    if(state==0){
      cur = min(r,*h[nowH].upper_bound(nowW));
      sum += cur - nowW - 1;
      r = cur-1;
      nowW = cur-1;
    }
    if(state==1){
      cur = min(d,*w[nowW].upper_bound(nowH));
      sum += cur - nowH - 1;
      d = cur-1;
      nowH = cur-1;
    }
    if(state==2){
      cur = max(l,*--h[nowH].lower_bound(nowW));
      sum += nowW - cur - 1;
      l = cur+1;
      nowW = cur+1;
    }
    if(state==3){
      cur = max(u,*--w[nowW].lower_bound(nowH));
      //debug(cur);
      sum += nowH - cur - 1;
      u = cur+1;
      nowH = cur+1;
    }
    state++;
    state %= 4;
    //debug(sum);
    //cout << nowH SP nowW << endl;
    if(pre == sum) break;
    pre = sum;
  }
 
 
  if(sum == n*m-k-1) cout << "Yes" << endl;
  else cout << "No" << endl;
 
  return 0;
}