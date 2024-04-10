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
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef pair<P,P> PP;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<P> a(n);
  REP(i,n){
    cin >> a[i].fs >> a[i].sc;
  }

  sort(a.begin(),a.end());

  int ans = 0;
  map<PP,int> mp;
  REP(i,n){
    FOR(j,i+1,n){
      int x = a[j].fs-a[i].fs, y = a[j].sc-a[i].sc;
      int g = __gcd(x,y);
      x /= g, y /= g;
      if(x == 0) y = 1;
      if(y == 0) x = 1;
      int u = x, v = a[i].sc*x-y*a[i].fs;
      int gg = __gcd(u,v);
      
      if(x == 0) u = a[i].fs , v = 0;
      else if(y == 0) u = 0, v = a[i].sc;
      else{u /= gg; v /= gg;}
      mp[PP(P(x,y),P(u,v))]++;
    }
  }

  map<P,int> mp2;
  int cnt = 0;
  ITR(itr,mp){
    cnt++;
    mp2[itr->fs.fs]++;
  }

  ITR(itr,mp2){
    ans += itr->sc*(itr->sc-1);
  }

  cout << cnt*(cnt-1)/2 - ans/2 << endl;

  return 0;
}