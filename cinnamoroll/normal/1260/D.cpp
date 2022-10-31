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

int m,n,k,t;
const int N = 2e5+10;
vec l(N),r(N),d(N);
bool check(int mid){
  vec used(n+5,0);
  REP(i,k){
    if(d[i]>mid) used[l[i]]++, used[r[i]+1]--;
  }
  int cnt = 0;
  REP(i,n+4){
    used[i+1] += used[i];
    if(used[i+1]) cnt++;
  }
  return t-cnt*2 >= 0;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n >> k >> t;

  t -= n+1;

  vector<int> a(m);
  REP(i,m) cin >> a[i];
  
  sort(a.rbegin(),a.rend());

  REP(i,k) cin >> l[i] >> r[i] >> d[i];

  int ng = m+1, ok = 0;
  while (abs(ng-ok)>1) {
    int mid = (ng+ok)/2;
    (check(a[mid-1])?ok:ng) = mid;
  }

  cout << ok << endl;

  return 0;
}