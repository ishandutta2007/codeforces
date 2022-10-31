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

int n,ans = 0;
vec a(202020), in(202020,-1);

void dfs(int l, int r, set<int> &st){
  if(st.size() < 3) return;
  int id = in[*st.rbegin()];
  st.erase(a[id]);

  set<int> tmp;
  if(id-l < r-id){
    FOR(i,l,id) tmp.insert(a[i]), st.erase(a[i]);
    FOR(i,l,id) if(st.count(a[id]-a[i])) ans++;
    dfs(l,id,tmp); dfs(id+1,r,st);
  }
  else{
    FOR(i,id+1,r) tmp.insert(a[i]), st.erase(a[i]);
    FOR(i,id+1,r) if(st.count(a[id]-a[i])) ans++;
    dfs(l,id,st); dfs(id+1,r,tmp);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  
  set<int> st;
  REP(i,n){
    cin >> a[i];
    st.insert(i+1);
    in[a[i]] = i;
  }
  
  dfs(0,n,st);

  cout << ans << endl;

  return 0;
}