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

  int MAX = 1e7 + 10, mn = INF;
  P ans;

  vec flag(MAX,0);
  REP(i,n){
    int a;
    cin >> a;
    if(flag[a] == 0) flag[a] = i+1;
    else if(mn > a) ans = P(flag[a],i+1),mn = a;
  }
  
  FOR(i,1,MAX/2){
    int tmp = 0, id;
    FOR(j,1,MAX){
      if(i*j > MAX) break;
      if(flag[i*j]){
        if(tmp){
          if(mn > tmp*j) ans = P(id,flag[i*j]), mn = tmp*j;
        }
        else tmp = i*j, id = flag[i*j];
      }
    }
  }

  if(ans.fs > ans.sc) swap(ans.fs,ans.sc);

  cout << ans.fs SP ans.sc << endl;

  return 0;
}