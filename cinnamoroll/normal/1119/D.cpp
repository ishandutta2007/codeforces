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

  set<int> s;
  int mn = INF, mx = -INF;
  REP(i,n){
    int x;
    cin >> x;
    s.insert(x);
    mn = min(mn,x);
    mx = max(mx,x);
  }

  vec tmp;
  int num = -1;
  ITR(itr,s){
    if(num == -1){
      num = *itr;
      continue;
    }
    tmp.push_back(*itr-num-1);
    num = *itr;
  }
  sort(tmp.begin(),tmp.end());

  int m = tmp.size();
  //debug(m);
  tmp.push_back(INF);
  vec sum(m+1,0);
  REP(i,m){
    sum[i+1] = sum[i] + tmp[i];
    //debug(sum[i+1]);
  }
  
  int q;
  cin >> q;
  REP(_,q){
    int l,r;
    cin >> l >> r;
    int len = r-l;
    int ans = mx+len-mn+1;
    int id = upper_bound(tmp.begin(),tmp.end(),len) - tmp.begin();
    //debug(id);
    int cur = sum[m]-sum[id]-len*(m-id);
    cout << ans-cur << " ";
  }
  cout << endl;

  return 0;
}