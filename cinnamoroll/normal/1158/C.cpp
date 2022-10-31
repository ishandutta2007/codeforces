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

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  set<int> flag;
  flag.insert(INF);
  vector<P> b(n);
  REP(i,n){
    if(*flag.begin() == i+1) flag.erase(i+1);
    if(a[i] == -1) a[i] = i+2;
    if(a[i] > *flag.begin()){
      cout << -1 << endl;
      return;
    }
    b[i] = P(a[i],i);
    flag.insert(a[i]);
  }

  sort(b.begin(),b.end());
  b.push_back(P(INF,0));
  
  vec ans(n);
  int cnt = 1,cur = -1;
  stack<int> st;
  REP(i,n+1){
    if(b[i].fs == cur) st.push(b[i].sc);
    else{
      while(st.size()){
        int id = st.top(); st.pop();
        ans[id] = cnt;
        cnt++;
      }
      cur = b[i].fs;
      st.push(b[i].sc);
    }
  }

  REP(i,n) cout << ans[i] << " ";
  cout << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  REP(_,t) solve();

  return 0;
}