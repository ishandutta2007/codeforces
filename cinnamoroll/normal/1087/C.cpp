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
typedef vector<vector<P> > Graph;

const int NMAX = 1e3;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  vector<int> x(3),y(3);
  REP(i,3) cin >> x[i] >> y[i];

  vector<P> tmp(3);
  REP(i,3) tmp[i] = P(x[i],y[i]);

  sort(tmp.begin(),tmp.end());

  vector<int> xcop,ycop;
  xcop = x;
  ycop = y;

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  vector<P> ans;
  int cnt = 0;
  while(tmp[0].fs+cnt < tmp[1].fs){
    ans.pb(P(tmp[0].fs+cnt,tmp[0].sc));
    cnt++;
  }
  cnt = 0;
  while(tmp[1].fs < tmp[2].fs-cnt){
    ans.pb(P(tmp[2].fs-cnt,tmp[2].sc));
    cnt++;
  }

  FOR(i,y[0],y[2]+1) ans.pb(P(tmp[1].fs,i));

  cout << ans.size() << endl;

  REP(i,ans.size()) cout << ans[i].fs << " " << ans[i].sc << endl;

  return 0;
}