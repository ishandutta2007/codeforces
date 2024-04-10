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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<P> a(m);
  REP(i,m) cin >> a[i].fs >> a[i].sc;

  vector<P> b(n);
  REP(i,n) b[i] = P(0,i+1);
  REP(i,m) b[a[i].fs-1].fs++, b[a[i].sc-1].fs++;

  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());

  REP(i,n){
    if(b[i].fs + b[i+1].fs < m) break;
    int k = b[i].sc;
    int x = -1,y = -1;
    bool f = true;
    REP(j,m){
      if(a[j].fs == k || a[j].sc == k) continue;
      if(x == -1) x = a[j].fs, y = a[j].sc;
      else{
        if(a[j].fs != x && a[j].sc != x) x = -2;
        if(a[j].fs != y && a[j].sc != y) y = -2;
      }
      if(x == -2 && y == -2){
        f = false;break;
      }
    }
    if(f){
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}