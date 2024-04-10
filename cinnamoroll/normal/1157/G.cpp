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

int n,m;
vector<vector<int>> a(222,vec(222));
void solve(int h, int w){

  REP(i,n){
    if(i == h) continue;
    REP(j,m){
      if(a[h][0]^a[h][j]^(j>w) != a[i][0]^a[i][j]) return;
    }
  }

  cout << "YES" << endl;
  vec H(n),W(m);
  REP(i,m){
    if(a[h][i]^(i>w)){
      W[i] = 1;
      REP(j,n){
        a[j][i] ^= 1;
      } 
    }
    else W[i] = 0;
  }

  REP(i,n){
    if(a[i][0]^(i>h)) H[i] = 1;
    else H[i] = 0;
  }

  REP(i,n) cout << H[i];
  cout << endl;
  REP(i,m) cout << W[i];
  cout << endl;
  exit(0);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  
  REP(i,n) REP(j,m) cin >> a[i][j];
  
  REP(i,n) REP(j,m) solve(i,j);

  cout << "NO" << endl;

  return 0;
}