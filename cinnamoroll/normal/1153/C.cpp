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

  int n;
  string s;
  cin >> n >> s;

  int a = 0, b = 0, c = 0;
  REP(i,n){
    if(s[i] == '(') a++;
    else if(s[i] == ')') b++;
    else c++;
  }

  if(n%2){
    cout << ":(" << endl;
    return 0;
  }

  int cur = 0;
  string ans;
  REP(i,n){
    if(s[i] == '(') ans += '(', cur++;
    else if(s[i] == ')') ans += ')', cur--;
    else{
      if(a < n/2) ans+= '(', cur++, a++;
      else ans += ')', cur--;
    }
    if(i != n-1 && cur <= 0){
      cout << ":(" << endl;
      return 0;
    }
  }

  if(cur == 0) cout << ans << endl;
  else cout << ":(" << endl;

  return 0;
}