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
#define D double
#define fs first
#define sc second
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

const int NMAX = 2e5+10;
vec build(int r, vec &a){
  vec ret;
  int id = r;
  ret.push_back(r);
  a[r]--;
  r--;
  while(a[r] >= 2) ret.push_back(r), a[r]--, r--;
  if(a[r] == 0) r++;
  while(r <= id){
    while(a[r]){
      ret.push_back(r);
      a[r]--;
    }
    r++;
  }
  return ret;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vec a(NMAX,0);
  REP(i,n){
    int x;
    cin >> x;
    a[x]++;
  }

  int ans = 0, cur = 0,r;
  FOR(i,1,NMAX){
    if(a[i] >= 2) cur += a[i];
    else{
      if(cur+a[i] > ans){
        ans = cur+a[i];
        r = i - (a[i]==0);
      }
      cur = a[i];
    }
  }

  cout << ans << endl;
  vec tmp = build(r,a);

  REP(i,tmp.size()) cout << tmp[i] << " ";

  return 0;
}