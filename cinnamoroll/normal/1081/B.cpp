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
#define range(i,a,b) (a)<=(i) && (i)<(b)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef pair<int,int> P;
typedef vector<vector<P>> Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  map<int,int> mp;
  REP(i,n) mp[n-a[i]]++;



  stack<int> st[n+1];
  int cnt = 1;
  ITR(i,mp){
    if(i->fs != 0 && i->sc % i->fs != 0){
      cout << "Impossible" << endl;
      return 0;
    }
    REP(j,i->sc){
      st[i->fs].push(cnt);
      if(i->fs != 0 && (j+1)%i->fs == 0) cnt++;
    }
  }

  cout << "Possible" << endl;
  REP(i,n){
    cout << st[n-a[i]].top() << " ";
    st[n-a[i]].pop();
  }

  cout << endl;

  return 0;
}