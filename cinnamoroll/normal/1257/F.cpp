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
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n),b(n);
  int mask = (1<<15)-1;
  REP(i,n){
    int x;
    cin >> x;
    a[i] = x&mask;
    b[i] = x>>15;
  }
  
  map<vec,int> mp;
  REP(i,1<<15){
    vec now(n);
    int mx = 0;
    REP(j,n){
      int k = a[j]^i;
      now[j] = pcnt(k);
      mx = max(mx,now[j]);
    }
    REP(j,n) now[j] = mx - now[j];
    mp[now] = i;
  }

  REP(i,1<<15){
    vec now(n);
    int mn = INF;
    REP(j,n){
      int k = b[j]^i;
      now[j] = pcnt(k);
      mn = min(mn,now[j]);
    }
    REP(j,n) now[j] -= mn;
    if(mp.count(now)){
      cout << (i<<15)+mp[now] << endl;
      return 0;
    } 
  }

  cout << -1 << endl;

  return 0;
}