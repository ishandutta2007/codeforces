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
//#define int long long
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

vec a;
vector<bool> used;
int n,m;

bool print(bool flag){
  if(a.size()==n) return false;
  sort(a.begin(),a.end());
  int id = 0;
  vec b;
  REP(i,n){
    if(id<a.size() && a[id]==i) id++;
    else b.push_back(i);
  }

  if(!flag) swap(a,b);

  cout << "Yes" << "\n" << a.size() SP b.size() << "\n";
  for(int x:a) cout << x+1 << " "; cout << "\n";
  for(int x:b) cout << x+1 << " "; cout << "\n";

  return true;
}

void dfs(int no,mat &edge){
  used[no] = true;
  a.push_back(no);
  for(int to:edge[no]){
    if(used[to]) continue;
    dfs(to,edge);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    cin >> n >> m;
    mat s(n), t(n);
    REP(i,m){
      int x,y;
      cin >> x >> y; x--; y--;
      if(x!=y){
        s[x].push_back(y);
        t[y].push_back(x);
      }
    }

    a.clear(); used.assign(n,false);
    dfs(0,s);
    if(print(true)) continue;
    a.clear(); used.assign(n,false);
    dfs(0,t);    
    if(!print(false)) cout << "No" << "\n";
  }

  return 0;
}