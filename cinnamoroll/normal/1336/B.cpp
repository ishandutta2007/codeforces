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
//
#include "bits/stdc++.h"
using namespace std;
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
int f(int x, int y){
  return abs(x-y)*abs(x-y);
}
 
int ans;
 
void solve(vec &a, vec &b, vec &c){
  int l = a.size(), m = b.size(), n = c.size();
  int u = 0, v = 0;
  REP(i,l){
    while(u < m && a[i] > b[u]) u++;
    while(v < n-1 && a[i] >= c[v+1]) v++;
    if(u==m||a[i] < c[v]) continue;
    chmin(ans,f(a[i],b[u])+f(a[i],c[v])+f(b[u],c[v]));
  }
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int q;
  cin >> q;
 
  REP(_,q){
    int l,m,n;
    cin >> l >> m >> n;
 
    vector<int> a(l);
    REP(i,l) cin >> a[i];
    
    vector<int> b(m);
    REP(i,m) cin >> b[i];
    
    vector<int> c(n);
    REP(i,n) cin >> c[i];
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
 
    ans = __LONG_LONG_MAX__;
    solve(a,b,c);
    solve(a,c,b);
    solve(b,a,c);
    solve(b,c,a);
    solve(c,a,b);
    solve(c,b,a);
 
    cout << ans << endl;
  }
 
  return 0;
}