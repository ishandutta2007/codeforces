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

vector<int> divisor(const int n){
  vector<int> ret;
  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      ret.pb(i);
      if(i*i!= n) ret.pb(n/i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  int q;
  cin >> q;

  vector<int> a(q);
  REP(i,q) cin >> a[i];
  
  vector<int> ans(q);
  REP(i,q){
    int tmp = 1;
    bool flag = true;
    while(tmp <= a[i]){
      if((tmp & a[i]) == 0) flag = false;
      tmp *= 2;
    }
    if(flag){
      vector<int> pos = divisor(a[i]);
      ans[i] = pos[pos.size()-2];
    }
    else ans[i] = tmp-1;
  }

  REP(i,q) cout << ans[i] << endl;

  return 0;
}