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
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
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

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int ans = 0;
  map<int,int> mp;
  vec tmp(1e5+10,0);
  REP(i,n){
    tmp[a[i]]++;
    mp[tmp[a[i]]]++;
    mp[tmp[a[i]]-1]--;
    if(mp[tmp[a[i]]-1] <= 0) mp.erase(tmp[a[i]]-1);
    //debug(mp.size());
    if(mp.size() == 1){
      if(mp.count(1)) ans = i+1;
      ITR(itr,mp) if(itr->sc == 1) ans = i+1;
    }
    else if(mp.size() > 2) continue;
    else{
      int x[2],y[2], id = 0;
      ITR(itr,mp) x[id] = itr->fs,y[id] = itr->sc, id++;
      if(x[0] == 1 && y[0] == 1) ans = i+1;
      else if(x[1]-x[0] == 1 && y[1] == 1) ans = i+1;
    }
  }

  cout << ans << endl;

  return 0;
}