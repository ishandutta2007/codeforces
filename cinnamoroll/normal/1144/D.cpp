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

  int n;
  cin >> n;

  vec a(n);
  REP(i,n) cin >> a[i];
  
  map<int,int> mp;
  REP(i,n) mp[a[i]]++;

  int mx = -1, num = -1;
  ITR(itr,mp) if(mx < itr->sc){
    mx = itr->sc;
    num = itr->fs;
  }

  int id = 0;
  while(a[id] != num) id++;

  cout << n - mx << endl;
  RREP(i,id){
    if(a[i] < num) cout << 1 SP i+1 SP i+2 << endl;
    else cout << 2 SP i+1 SP i+2 << endl;
  }
  FOR(i,id,n){
    if(a[i] == num) continue;
    if(a[i] < num) cout << 1 SP i+1 SP i << endl;
    else cout << 2 SP i+1 SP i << endl;
  }

  return 0;
}