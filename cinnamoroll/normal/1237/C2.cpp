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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> x(n),y(n),z(n);
  REP(i,n) cin >> x[i] >> y[i] >> z[i];
  
  vec a(n);
  REP(i,n) a[i] = i;

  auto comp = [&](int a, int b){
    if(x[a] != x[b]) return x[a] < x[b];
    if(y[a] != y[b]) return y[a] < y[b];
    return z[a] < z[b];
    };

  sort(a.begin(),a.end(),comp);

  vector<P> ans;
  vec b;
  REP(i,n){
    if(a.size() != i+1 && x[a[i]]==x[a[i+1]] && y[a[i]]==y[a[i+1]]){
      ans.push_back(P(a[i],a[i+1]));
      i++;
    }
    else b.push_back(a[i]);
  }

  vec c;
  REP(i,b.size()){
    if(b.size() != i+1 && x[b[i]]==x[b[i+1]]){
      ans.push_back(P(b[i],b[i+1]));
      i++;
    }
    else c.push_back(b[i]);
  }

  REP(i,c.size()) ans.push_back(P(c[i],c[i+1])), i++;

  REP(i,n/2) cout << ans[i].fs +1 SP ans[i].sc + 1 << endl;

  return 0;
}