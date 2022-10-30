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

  int n;
  cin >> n;

  map<int,int> mp;

  vector<int> a(n);
  REP(i,n) cin >> a[i], mp[a[i]] = i+1;

  sort(a.begin(),a.end());
  
  vec b(n-1);
  REP(i,n-1) b[i] = a[i+1]-a[i];

  int id = 0;
  while(id < n-2){
    if(b[id] == b[id+1]) id++;
    else break;
  }

  //debug(id);

  if(id == n-2){
    cout << mp[a[0]] << endl;
    return 0;
  }

  bool flag = true;
  FOR(i,id+3,n-1){
    if(b[id] != b[i]) flag = false;
  }

  if(id+3 < n && b[id] != a[id+3]-a[id+1]) flag = false;

  //debug(a[id+2]);

  if(flag) cout << mp[a[id+2]] << endl;
  else{
    bool flag2 = true;
    int cur = a[2]-a[1];
    REP(i,n-2) if(cur != a[i+2]-a[i+1]) flag2 = false;
    if(flag2){
      cout << mp[a[0]] << endl;
      return 0;
    }
    flag2 = true;
    cur = a[2]-a[0];
    REP(i,n-3) if(cur != a[i+3]-a[i+2]) flag2 = false;
    if(flag2) cout << mp[a[1]] << endl;
    else cout << -1 << endl;
  }

  return 0;
}