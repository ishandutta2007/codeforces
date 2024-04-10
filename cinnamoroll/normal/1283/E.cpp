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
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  sort(a.begin(),a.end());

  int mn = 0;
  vec flag(n+2,0);
  REP(i,n){
    if(flag[a[i]] || flag[a[i]-1] || flag[a[i]+1]) continue;
    mn++;
    flag[a[i]+1]++;
  }

  int mx = 0;
  flag.assign(n+2,0);
  REP(i,n){
    if(!flag[a[i]-1]) mx++, flag[a[i]-1]++;
    else if(!flag[a[i]]) mx++, flag[a[i]]++;
    else if(!flag[a[i]+1]) mx++, flag[a[i]+1]++;
  }

  cout << mn SP mx << endl;

  return 0;
}