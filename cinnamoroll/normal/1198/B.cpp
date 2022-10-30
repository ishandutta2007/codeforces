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
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int q;
  cin >> q;
  vec mx = {-1},in = {-1},id(n,-1);
  REP(i,q){
    int x,y;
    cin >> x >> y;
    if(x == 1){
      int z;
      cin >> z, a[y-1] = z, id[y-1] = i;
    }
    else{
      mx.emplace_back(y); in.emplace_back(i);
    }
  }

  mx.emplace_back(-INF); in.emplace_back(INF);

  RREP(i,mx.size()-1) mx[i] = max(mx[i],mx[i+1]);

  REP(i,n){
    int index = lower_bound(in.begin(),in.end(),id[i]) - in.begin();
    a[i] = max(a[i],mx[index]);
  }

  REP(i,n) cout << a[i] << " ";
  cout << endl;

  return 0;
}