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
#define INF (1LL<<60)
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
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n,m;
  cin >> n >> m;
 
  int mx = 0;
  REP(i,n) mx += max(0LL,n-2*(i+1));
 
  if(mx < m){
    cout << -1 << endl;
    return 0;
  }
 
  vec cnt(n,0);
  int x = (n-1)/2;
  REP(i,n) cnt[i] = i/2;
 
 vec ans(n); REP(i,n) ans[i] = i+1;
  int val = 1e9, now = mx;
  RREP(i,n){
    //debug(now);
    if(now-cnt[i] > m){
      ans[i] = val;
      val -= 5050;
      now -= cnt[i];
    }
    else{
      int u = m-now+cnt[i];
      //debug(u);
      while(1){
        int tmp = 0;
        REP(j,i-1) if(range(ans[i]-(j+1),j+2,i+1)) tmp++;
        if(tmp==u)break;
        ans[i]++;
      }
      break;
    }
  }
 
  REP(i,n) cout << ans[i] << " ";
  cout << endl;
 
  return 0;
}