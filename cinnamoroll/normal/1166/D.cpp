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

  int q;
  cin >> q;

  REP(_,q){
    int a,b,m;
    cin >> a >> b >> m;
    
    if(a == b){
      cout << 1 SP a << endl;
      continue;
    }

    int cur = a+1, len = 2;
    while(cur <= b){
      int cnt = b - cur;
      vec tmp(len,1);
      FOR(i,1,len){
        int base = (1LL<<max(0LL,len-2-i));
        //debug(base);
        int r = min(m-1,cnt/base);
        tmp[i] += r;
        cnt -= r*base;
      }
      if(cnt == 0){
        cout << len SP a;
        FOR(i,1,len){
          cout << " " << a + tmp[i];
          a += a + tmp[i];
        }
        cout << endl;
        goto out;
      }
      len++; cur *= 2;
    }
    cout << -1 << endl;
    out:;
  }

  return 0;
}