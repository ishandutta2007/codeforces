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

const int NMAX = 2e5;
vector<int> edge[NMAX],color(NMAX,0);

bool isBip(int no){
  if(color[no] == 0) color[no] = 1;
  for(auto to:edge[no]){
    if(color[no] == color[to]) return false;
    else if(color[to] == 0){
      color[to] = -color[no];
      if(!isBip(to)) return false;
    }
  }
  return true;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vec x(m),y(m);
  REP(i,m){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
    edge[x[i]].push_back(y[i]);
    edge[y[i]].push_back(x[i]);
  }
  
  if(!isBip(0)) cout << "NO" << endl;
  else{
    cout << "YES" << endl;
    REP(i,m){
      if(color[x[i]] == 1) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }


  return 0;
}