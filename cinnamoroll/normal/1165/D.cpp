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

vector<int> divisor(const int n){
  vector<int> ret;
  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      ret.push_back(i);
      if(i*i!= n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  
  REP(_,t){
    int n;
    cin >> n;

    vector<int> a(n);
    REP(i,n) cin >> a[i];
    
    sort(a.begin(),a.end());
    int ans = a[0]*a.back();
    vec tmp = divisor(ans);

    if(tmp.size() - n != 2){
      cout << -1 << endl;
      continue;
    }

    bool flag = true;
    REP(i,n){
      if(tmp[i+1] != a[i]) flag = false;
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
  }

  return 0;
}