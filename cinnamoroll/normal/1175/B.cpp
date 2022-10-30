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

  int t;
  cin >> t;

  int ans = 0, cur = 1, ok = 0;
  int mx = (1LL<<32)-1;
  stack<int> st;
  bool f = false;
  REP(i,t){
    string s;
    cin >> s;
    int x;
    if(s == "for") cin >> x;
    if(f) continue;
    if(s == "add"){
      if(st.size() > ok || ans + cur > mx){
        f = true;
      }
      else ans += cur;
    }
    else if(s == "end"){
      if(st.size() <= ok) cur /= st.top();
      st.pop();
      ok = min(ok,(int)st.size());
    }
    else{
      st.push(x);
      if(cur*x <= mx && st.size() == ok+1) ok = st.size(), cur *= x;
    }
  }

  if(f) cout << "OVERFLOW!!!" << endl;
  else cout << ans << endl;

  return 0;
}