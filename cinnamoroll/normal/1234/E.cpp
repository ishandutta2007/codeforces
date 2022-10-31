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

  int n,m;
  cin >> n >> m;

  vector<int> a(m);
  REP(i,m) cin >> a[i], a[i]--;
  
  int now = 0;
  REP(i,m-1) now += abs(a[i]-a[i+1]);

  //debug(now);

  vec flip(n+1,0), pos(n+1,0), neg(n+1,0);
  REP(i,m-1){
    if(a[i] < a[i+1]) flip[a[i+1]] += a[i]+1-(a[i+1]-a[i]);
    else if(a[i+1]<a[i]) flip[a[i]] += a[i+1]+1-(a[i]-a[i+1]);
    if(a[i]!=a[i+1]){
      pos[min(a[i],a[i+1])] += min(a[i],a[i+1]);
      neg[min(a[i],a[i+1])+1]++;
      neg[max(a[i],a[i+1])]--;
    }
  }

  REP(i,n) neg[i+1] += neg[i];

  REP(i,n){
    //cout << flip[i] SP pos[i] SP neg[i] << endl;
    cout << now + flip[i] + pos[i] - neg[i] << " ";
  }

  return 0;
}