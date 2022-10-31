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

  int n,q;
  cin >> n >> q;

  deque<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<P> b(q);
  REP(i,q) cin >> b[i].fs, b[i].sc = i;
  
  sort(b.begin(),b.end());

  vector<P> ans(q);

  int id = 0;
  FOR(i,1,n+1){
    int x = a[0], y = a[1]; a.pop_front(); a.pop_front();
    while(id < q && b[id].fs == i) ans[b[id].sc] = P(x,y), id++;
    if(x < y) swap(x,y);
    a.push_front(x);
    a.push_back(y);
  }

  FOR(i,id,q){
    int in = (b[i].fs-n)%(n-1);
    if(in == 0) in = n-1;
    ans[b[i].sc] = P(a[0],a[in]);
  }

  REP(i,q) cout << ans[i].fs SP ans[i].sc << endl;


  return 0;
}