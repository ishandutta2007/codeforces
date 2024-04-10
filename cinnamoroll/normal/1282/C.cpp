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
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
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
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t;
  cin >> t;
 
  REP(_,t){
    int n,t,x,y;
    cin >> n >> t >> x >> y;
    t++;

    vector<int> a(n);
    REP(i,n) cin >> a[i];
    
    vector<int> b(n);
    REP(i,n) cin >> b[i];

    vector<P> c(n);
    int u = 0, v = 0;
    REP(i,n) c[i] = P(b[i],(a[i]?y:x)), (a[i]?v:u)++;
    c.emplace_back(t,0);
    sort(c.begin(),c.end());
    
    int now = 0, ans = 0;
    REP(i,n+1){
      int cur = c[i].fs - now - 1;
      if(cur >= 0){
        int tmp = i;
        tmp += min(cur/x,u);
        cur -= min(cur/x,u)*x;
        tmp += min(cur/y,v);
        cur -= min(cur/y,v)*y;
        ans = max(ans,tmp);
        //debug(tmp);
      }
      now += c[i].sc;
      (c[i].sc==x?u:v)--;
    }

    cout << ans << "\n";

  }
 
  return 0;
}