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

bool check(int x){
  int tmp = 2;
  while(tmp <= x*2){
    if(x == tmp-1) return true;
    tmp *= 2;
  }
  return false;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x;
  cin >> x;

  vec ans;
  int cnt = 0;
  while(1){
    if(check(x)) break;
    //debug(x);
    int in = 0, cur = -1;
    while((1LL<<in) < x){
      if(((1LL<<in) & x) == 0) cur = in;
      in++;
    }
    x ^= ((1LL<<(cur+1))-1);
    ans.push_back(cur+1);
    cnt++;
    if(check(x)) break;
    x++;
    cnt++;
  }

  cout << cnt << endl;
  REP(i,ans.size()) cout << ans[i] << " ";
  cout << endl;

  return 0;
}