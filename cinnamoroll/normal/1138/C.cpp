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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //
  //DP

  int n,m;
  cin >> n >> m;

  mat a(n,vec(m));
  REP(i,n) REP(j,m) cin >> a[i][j];

  mat v(n,vec(m)), h(n,vec(m)); //
  vec h_num(m), v_num(n); //

  REP(i,n){
    map<int,int> mp; //
    REP(j,m) mp[a[i][j]]++;
    int id = 1; //
    ITR(itr,mp) itr->sc = id, id++;
    v_num[i] = mp.size();
    REP(j,m) v[i][j] = mp[a[i][j]];
  }

  REP(i,m){
    map<int,int> mp;
    REP(j,n) mp[a[j][i]]++;
    int id = 1;
    ITR(itr,mp) itr->sc = id, id++;
    h_num[i] = mp.size();
    REP(j,n) h[j][i] = mp[a[j][i]];
  }

  mat ans(n,vec(m));
  REP(i,n){
    REP(j,m){
      int tmp = max(h[i][j],v[i][j]); //
      tmp += max(h_num[j]-h[i][j],v_num[i]-v[i][j]); //ij 
      ans[i][j] = tmp;
    }
  }

  REP(i,n){
    REP(j,m) cout << ans[i][j] << " ";
    cout << endl;
  }

  return 0;
}