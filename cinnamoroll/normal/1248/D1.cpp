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

  int n;
  string s;
  cin >> n >> s;

  int f = 0;
  REP(i,n) f += (s[i]=='('?1:-1);

  if(f){
    cout << 0 << endl << 1 SP 1 << endl;
    return 0;
  }

  int ans = 1, l = 1, r = 1;
  REP(i,n){
    FOR(j,i+1,n){
      string t = s;
      swap(t[i],t[j]);
      vec sum(n+1,0);
      int mn = 0;
      REP(k,n){
        sum[k+1] = sum[k]+(t[k]=='('?1:-1);
        mn = min(mn,sum[k+1]);
      }
      int cnt = 0;
      REP(k,n) if(sum[k+1]==mn) cnt++;
      //cout << mn SP cnt << endl;
      if(ans < cnt){
        ans = cnt; l = i+1; r = j+1;
      }
    }
  }

  cout << ans << endl << l SP r << endl;

  return 0;
}