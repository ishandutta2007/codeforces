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
  string s;
  cin >> n >> s;

  int mn = INF;

  FOR(i,1,n){
    if(s[i] == '0') continue;
    mn = min(mn,max(i,n-i)+1);
  }

  vec ans(n+1,10);
  FOR(i,1,n){
    if(s[i] == '0' || max(i,n-i) > mn) continue;
    vec tmp(n+1,0);
    int id = n;
    RREP(j,i) tmp[id] += s[j]-'0', id--;
    id = n;
    RFOR(j,i,n){
      tmp[id] += s[j]-'0';
      if(tmp[id] > 9) tmp[id] -= 10, tmp[id-1]++;
      id--;
    }
    while(id >= 0){
      if(tmp[id] > 9) tmp[id] -= 10, tmp[id-1]++;
      id--;
    }
    if(ans > tmp) ans = tmp;
  }

  bool f = true;
  REP(i,n+1){
    if(ans[i]) f = false;
    if(f) continue;
    cout << ans[i];
  }

  cout << endl;

  return 0;
}