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

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vec ans;
  set<int> st; int cnt = 0;
  vec last(1e6+10,-1);
  REP(i,n){
    cnt++;
    if(a[i]>0){
      st.insert(a[i]);
      if(last[a[i]]==ans.size()){
        cout << -1 << endl;
        return 0;
      }
      last[a[i]] = ans.size();
    }
    else{
      if(st.find(-a[i])==st.end()){
        cout << -1 << endl;
        return 0;
      }
      else st.erase(st.find(-a[i]));
      if(st.size()==0) ans.push_back(cnt), cnt = 0;
    }
  }

  if(cnt) cout << -1 << endl;
  else {
    cout << ans.size() << endl;
    REP(i,ans.size()) cout << ans[i] << " ";
  }

  return 0;
}