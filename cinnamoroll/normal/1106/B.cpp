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
#define INF 1LL<<60
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<int> b(n);
  REP(i,n) cin >> b[i];
  
  vector<int> x(m),y(m);
  REP(i,m) cin >> x[i] >> y[i], x[i]--;

  vector<P> tmp(n);
  REP(i,n) tmp[i] = P(b[i],i);

  sort(tmp.begin(),tmp.end());
  
  int id = 0;
  REP(i,m){
    if(a[x[i]] >= y[i]){
      cout << b[x[i]]*y[i] << endl;
      a[x[i]] -= y[i];
      continue;
    }
    int ans = 0;
    ans += b[x[i]]*a[x[i]];
    y[i] -= a[x[i]];
    a[x[i]] = 0;
    while(y[i] && id < n){
      int index = tmp[id].sc;
      int cur =  min(y[i],a[index]);
      ans += cur*b[index];
      a[index] -= cur;
      y[i] -= cur;
      if(a[index] == 0) id++;
    }
    if(y[i] == 0) cout << ans << endl;
    else cout << 0 << endl;
  }

  return 0;
}