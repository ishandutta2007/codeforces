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

  int n,k;
  cin >> n >> k;
  
  vector<int> x(k);
  REP(i,k) cin >> x[i], x[i]--;
  
  int ans = 0;
  set<int> st[n];
  REP(i,k) st[x[i]].insert(i);
  
  REP(i,n){
    if(st[i].size() == 0){
        if(i != 0 && i != n-1)ans+= 3;
        else ans += 2;
        continue;
    }
    //debug(ans);
    if(i != 0 && (st[i-1].size() == 0 || *st[i].begin() > *st[i-1].rbegin())) ans++;
    //debug(ans);
    //if(st[i].size() && i-1 >= 0 && st[i-1].size())cout << *st[i].begin() SP *st[i-1].rend() << endl;
    if(i != n-1 && (st[i+1].size() == 0 || *st[i].begin() > *st[i+1].rbegin())) ans++;
    //debug(ans);
  }

  cout << ans << endl;

  return 0;
}