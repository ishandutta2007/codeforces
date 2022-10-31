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

const int NMAX = 300;
int n,m,num = 0;
vector<int> a(NMAX),l(NMAX),r(NMAX),ans;

void calc(int s, int t){
  int mn = a[s], mx = a[t];
  vector<int> tmp;
  REP(i,m){
    if(range(s,l[i]-1,r[i]) && !range(t,l[i]-1,r[i])){
      mn--;
      tmp.pb(i);
    }
  }
  if(mx-mn > num){
    num = mx-mn;
    ans = tmp;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  cin >> n >> m;

  REP(i,n) cin >> a[i];
  
  REP(i,m) cin >> l[i] >> r[i];
  
  REP(i,n){
    REP(j,n){
      if(i == j) continue;
      calc(i,j);
    }
  }

  cout << num << endl;
  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i]+1 << " ";

  return 0;
}