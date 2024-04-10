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

mat pre(3e5+20,vec(25));

int calc(int l, int r){
  int id = 20;
  while((1<<id) > r-l) id--;
  return max(pre[l][id],pre[r-(1<<id)][id]);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int mn = INF, mx = -INF;
  vector<int> a(n);
  REP(i,n) cin >> a[i], mn = min(mn,a[i]), mx = max(mx,a[i]);
  
  if(mn*2 >= mx){
    REP(_,n) cout << -1 << " ";
    cout << endl;
    return 0;
  }

  vec b = a;
  REP(i,2*n+10) b.push_back(b[i]);

  int m = b.size();
  
  REP(i,m) pre[i][0] = b[i];

  REP(j,20){
    REP(i,m) if(i+(1<<j) < m) pre[i][j+1] = max(pre[i][j],pre[i+(1<<j)][j]);
  }

  int res = 1;
  REP(i,n){
    if(res>1) res--;
    while(calc(i,i+res) <= b[i+res]*2) res++;
    cout << res << " ";
  }

  return 0;
}