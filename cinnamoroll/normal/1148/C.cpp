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
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int N = 3e5+10;
  vector<int> a(N);
  vec id(N);
  vector<P> ans;

void change(int x, int y){
  swap(id[x],id[y]);
  swap(a[id[x]],a[id[y]]);
  ans.push_back(P(id[x],id[y]));
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  FOR(i,1,n+1) cin >> a[i], id[a[i]] = i;

  REP(i,n/2){
    if(id[n/2-i] != n/2-i){
      if(id[n/2-i] > n/2) change(a[1],n/2-i);
      //REP(j,n) cout << a[j+1] << " ";
      //cout << endl;
      change(n/2-i,a[n]);
      change(n/2-i,a[n/2-i]);
    }
    if(id[n/2+1+i] != n/2+1+i){
      if(id[n/2+1+i] <= n/2) change(n/2+1+i,a[n]);
      change(a[1],n/2+1+i);
      change(a[n/2+1+i],n/2+1+i);      
    }
  }

  cout << ans.size() << endl;
  REP(i,ans.size()){
    cout << ans[i].fs SP ans[i].sc << endl;
    assert(abs(ans[i].fs-ans[i].sc)*2 >= n);
  }

  //REP(i,n) cout << a[i] << endl;

  return 0;
}