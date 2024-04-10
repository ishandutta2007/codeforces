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

  int n,k;
  cin >> n >> k;

  using T = tuple<int,int,int>;
  vector<T> a(n);
  REP(i,n){
    int l,r;
    cin >> l >> r;
    a[i] = T(l,r,i);
  }

  sort(a.begin(),a.end());

  multiset<P> st;
  vec ans;
  REP(i,n){
    int l,r,id;
    tie(l,r,id) = a[i];
    st.insert(P(r,id+1));
    while(st.size() && (*st.begin()).fs < l) st.erase(st.find(*st.begin()));
    while(st.size() > k){
      ans.push_back((*st.rbegin()).sc);
      st.erase(st.find(*st.rbegin()));
    }
  }

  cout << ans.size() << endl;
  for(int x:ans) cout << x << " ";

  return 0;
}