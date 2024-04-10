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

  int n,x;
  cin >> n >> x;

  vector<int> a(n);
  REP(i,n) cin >> a[i], a[i]--;
  
  vec front(x,-1), back(x,-1);
  REP(i,n){
    if(front[a[i]] == -1) front[a[i]] = i;
    back[a[i]] = i;
  }

  int l = -1, r = INF, cnt = 0;
  while(x-cnt-1 >= 0 && (r > back[x-cnt-1] || back[x-cnt-1] == -1)){
    if(front[x-cnt-1] != -1) r = front[x-cnt-1];
    cnt++;
  }

  if(cnt == x) {
    cout << x*(x+1)/2 << endl;
    return 0;
  }

  front.push_back(INF);

  int ans = 0,cur = cnt;
  REP(i,x){
    ans += cnt+1;
    if(front[i] != -1 && front[i] <= l) break;
    if(back[i] != -1) l = back[i];
    while(cnt > 0 && r < l){
      cur--;
      if(front[x-cur] != -1){
        r = front[x-cur];
        if(r < l) cnt = cur;
        else cnt--;
      }
    }
  }
  
  cout << ans << endl;

  return 0;
}