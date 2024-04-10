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

  vector<int> a(n);
  map<int,int> mp;
  REP(i,n) cin >> a[i], mp[a[i]]++;

  vec cnt(n+10,0); int mx = 0;
  ITR(itr,mp) cnt[itr->sc]++, mx = max(mx,itr->sc);
  
  int sum = 0, tmp = mp.size();
  int h,w,ans = 0;
  FOR(i,1,n+1){
    sum += tmp;
    tmp -= cnt[i];
    int j = i;
   while(1){
      int k = sum/j;
      if(k < j) break;
      if(ans < j*k){
        ans = j*k;
        h = j, w = k;
      }
      j++;
    }
  }

  //h = 3; w = 4;
  if(h>w) swap(h,w);

  cout << ans << endl << h SP w << endl;
  mat res(h,vec(w));
  vector<P> val;
  ITR(itr,mp){
    int x = min({itr->sc,h*w-val.size(),h});
    REP(_,x) val.push_back(P(x,itr->fs));
  }
  sort(val.rbegin(),val.rend());
  auto itr = mp.begin();
  int t = h*w/__gcd(h,w); int base = 0;
  REP(x,h*w){
    if(x%t==0) base++;
    int i = (x+base)%h, j = x%w;
    res[i][j] = val[x].sc;
  }

  REP(i,h){
    REP(j,w) cout << res[i][j] << " ";
    cout << endl;
  }

  return 0;
}