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

int calc(int x, int k){
  if(x < k) return x;
  int cnt = (x+k-1)/k;
  //cout << x SP k SP (x/k)*(x/k)*(k-x%k) + (x/k+1)*(x/k+1)*(x%k) << endl;
  return (x/k)*(x/k)*(k-x%k) + (x/k+1)*(x/k+1)*(x%k);
}

void solve(){
  int N,K;
  cin >> N >> K;

  priority_queue<T,vector<T>> que;
  REP(i,N){
    int x; cin >> x;
    que.push(T(calc(x,1)-calc(x,2),1,x));
   // debug(calc(x,1)-calc(x,2));
  }
  
  K -= N;
  while(K--){
    int x,y,z;
    tie(x,y,z) = que.top(); que.pop();
    //cout << x SP y SP z << endl;
    que.push(T(calc(z,y+1)-calc(z,y+2),y+1,z));
  }

  int ans = 0;
  while(que.size()){
    int x,y,z;
    tie(x,y,z) = que.top(); que.pop();
    ans += calc(z,y);
  }
  cout << ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}