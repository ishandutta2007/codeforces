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
#define D double
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

  int n,m,k;
  cin >> n >> m >> k;

  vector<tuple<int,int,int>> tmp(m);
  REP(i,m){
    int x,y,c;
    cin >> x >> y >> c;
    x--; y--;
    tmp[i] = tie(c,x,y);
  }

  sort(tmp.begin(),tmp.end());

  set<int> st;
  int t = min(k,m);
  REP(i,t){
    int x,y,c;
    tie(c,x,y) = tmp[i];
    st.insert(x);
    st.insert(y);
  }

  map<int,int> mp;
  int id = 0;
  for(auto itr = st.begin(); itr != st.end(); itr++) mp[*itr] = id, id++;

  mat dist(id,vec(id,INF));
  REP(i,id) dist[i][i] = 0;
  REP(i,t){
    int x,y,c;
    tie(c,x,y) = tmp[i];
    dist[mp[x]][mp[y]] = dist[mp[y]][mp[x]] = c;    
  }
  
  REP(k,id){
    REP(i,id){
      REP(j,id){
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
      }
    }
  }

  vec ans;
  REP(i,id) REP(j,id) ans.push_back(dist[i][j]);

  sort(ans.begin(),ans.end());

  cout << ans[id+k*2-1] << endl;

  return 0;
}