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
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
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

  int m,a,b;
  cin >> m >> a >> b;

  vec step(a+b,-1); //i
  int cur = 0, tmp = 0;
  while(1){
    step[cur] = tmp;
    if(cur >= b) cur -= b;
    else cur += a;
    if(cur == 0) break; //
    tmp = max(tmp,cur);
  }

  int ans = 0;
  REP(i,a+b) if(step[i] != -1) ans += max(0LL,m+1-step[i]);

  if(m > a+b-1){
    int l = a+b, r = m;
    int g = __gcd(a,b);
    int f = 1;
    while(l%g) l++;
    while(r%g) r--, f++;
    int dist = (r-l)/g;
    ans += (f+f+g*dist)*(dist+1)/2;
  }

  cout << ans << endl;

  return 0;
}