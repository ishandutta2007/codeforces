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

const int NMAX = 5555;
vector<int> g[NMAX],ans(NMAX,-1); // g[i][j]-> ij
vector<P> edge[NMAX];
int h[NMAX]; //h[i]-> i
int v,e;

vector<int> t_sort(){
  stack<int> st;
  REP(i, v) if(h[i] == 0) st.push(i);
  vector<int> res;
  while(st.size()) {
    int i = st.top(); st.pop();
    res.push_back(i);
    for(auto& j: g[i]) {
      h[j]--;
      if(h[j] == 0) st.push(j);
    }
  }
  return res;
}
// v,e
// res.size()v

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  v = n; e = m;

  vector<P> a(m);
  REP(i,m){
    cin >> a[i].fs >> a[i].sc;
    a[i].fs--; a[i].sc--;
    edge[a[i].fs].emplace_back(P(a[i].sc,i));
    g[a[i].fs].emplace_back(a[i].sc);
    h[a[i].sc]++;
  }
  
  vec tmp = t_sort();
  
  if(tmp.size() == n){
    cout << 1 << endl;
    REP(i,m) cout << 1 << " ";
    cout << endl;
  }
  else{
    cout << 2 << endl;
    REP(i,m){
      if(a[i].fs < a[i].sc) cout << 1 << " ";
      else cout << 2 << " ";
    }
    cout << endl;
  }

  return 0;
}