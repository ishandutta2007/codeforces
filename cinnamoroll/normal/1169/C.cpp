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

const int N = 3e5+10;
vector<int> a(N);
int n,m;

bool check(int mid){
  int cur = 0;
  REP(i,n){
    int l = a[i], r = (a[i]+mid)%m;
    //cout << l SP r << endl;
    if(l <= r){
      if(r < cur) return false;
      cur = max(cur,l);
    }
    else{
      if(cur <= r) continue;
      else if(cur < l) cur = l;
      else continue;
    }
    //debug(cur);
  }
  return true;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  
  REP(i,n) cin >> a[i];
  
  int ng = -1, ok = m;
  while (abs(ng-ok)>1) {
    //cout << ok << endl;
    int mid = (ng+ok)/2;
    (check(mid)?ok:ng) = mid;
  }

  cout << ok << endl;

  return 0;
}