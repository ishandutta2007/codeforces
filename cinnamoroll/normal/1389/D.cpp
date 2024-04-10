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
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void solve(){
  int N,K,l1,r1,l2,r2;
  cin >> N >> K >> l1 >> r1 >> l2 >> r2;

  if(l1 > l2) swap(l1,l2), swap(r1,r2);

  if(r1 <= l2){
    int x = l2-r1; // base cost
    int len = r2-l1; // score of one segment
    int ans = LINF, now = 0;
    REP(_,N){
      if(K > len){
        K -= len;
        now += x + len;
      }
      else{
        now += x + K;
        K = 0;
        break;
      }
      chmin(ans, now + K*2);
    }
    cout << min(ans, now + K*2) << endl;
  }

  else{
    int len = max(r1,r2)-l1; // score of one segment
    if(r1 < r2) K -= (r1-l2)*N, len -= (r1-l2);
    else K -= (r2-l2)*N, len -= (r2-l2);
    chmax(K,0LL); 
    int ans = LINF, now = 0;
    REP(_,N){
      if(K > len){
        K -= len;
        now += len;
      }
      else{
        now += K;
        K = 0;
        break;
      }
      chmin(ans, now + K*2);
    }
    cout << min(ans, now + K*2) << endl;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}