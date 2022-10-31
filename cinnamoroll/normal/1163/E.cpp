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
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
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

const int N = 2e5+10;
int n;
vector<int> a(N);

vec gray_code(int k, vec &list){
  vec res = {0};
  REP(i,k){
    RREP(j,1<<i){
      res.push_back(res[j]^list[i]);
    }
  }
  return res;
}

void check(int k){
  vec list;
  set<int> base;
  REP(i,n){
    if(a[i] >= (1<<k)) continue;
    int tmp = a[i];
    RITR(itr,base) tmp = min(tmp,tmp^*itr);
    if(tmp){
      base.insert(tmp);
      list.push_back(a[i]);
    }
  }
  if(base.size() == k){
    vec ans = gray_code(k,list);
    cout << k << endl;
    REP(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
    exit(0);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  REP(i,n) cin >> a[i];
  
  RREP(i,20) check(i);

  return 0;
}