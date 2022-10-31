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

const int N = 2e5+10;
vector<int> edge[N],color(N,-1);

void Bip(int no){
  if(color[no] == -1) color[no] = 1;
  for(int to:edge[no]){
    if(color[to] == -1){
      color[to] = color[no]^1;
      Bip(to);
    }
  }
}

int mx = 0, id = 0;
void dfs(int no, int dep, int par){
  if(mx < dep) mx = dep, id = no;
  for(int to: edge[no]){
    if(to==par) continue;
    dfs(to,dep+1,no);
  }
}

vec dist_s(N,0), dist_t(N,0);
void dfs2(int no, int par, vec &dist){
  for(int to: edge[no]){
    if(to==par) continue;
    dist[to] = dist[no]+1;
    dfs2(to,no,dist);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  REP(_,n-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  //2OK
  if(k == 2){
    Bip(0);
    cout << "Yes" << endl;
    REP(i,n) cout << color[i]+1 << " ";
    cout << endl;
    return 0;
  }

  int s,t;
  dfs(0,0,-1);
  s = id;
  mx = 0;
  dfs(id,0,-1);
  t = id;

  //OK
  if(mx < k-1){
    cout << "Yes" << endl;
    REP(i,n) cout << 1 << " ";
    cout << endl;
    return 0;
  }

  //
  dfs2(s,-1,dist_s);
  dfs2(t,-1,dist_t);

  vec ans(n);
  REP(i,n){
    if(dist_s[i]+dist_t[i]!=mx && dist_s[i]>=k-1&&dist_t[i]>=k-1){
      cout << "No" << endl;
      return 0;
    }
    if(dist_s[i]+dist_t[i]==mx || dist_s[i]>dist_t[i]) ans[i] = dist_s[i]%k;
    else ans[i] = (mx-dist_t[i])%k;
  }

  cout << "Yes" << endl;
  REP(i,n) cout << ans[i]+1 << " ";
  cout << endl;

  return 0;
}