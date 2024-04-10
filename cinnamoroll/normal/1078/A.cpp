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
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<double,double> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void solve(){
  double a,b,c;
  int x1,y1,x2,y2;
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

  if(x1 > x2) swap(x1,x2), swap(y1,y2);

  vector<P> p;
  double k;
  k = -(a*x1+c)/b;
  if(range(k,min(y1,y2),max(y1,y2))) p.emplace_back(x1,k);
  k = -(a*x2+c)/b;
  if(range(k,min(y1,y2),max(y1,y2))) p.emplace_back(x2,k);
  k = -(b*y1+c)/a;
  if(range(k,x1,x2)) p.emplace_back(k,y1);
  k = -(b*y2+c)/a;
  if(range(k,x1,x2)) p.emplace_back(k,y2);

  double tmp = abs(x1-x2)+abs(y1-y2), tmp2 = 1e18; int s,t;
  if(p.size() < 2) ;
  else{
    assert(p.size()==2);
    tmp2 = 0;
    double ans = 0;
    if(p[0].fs == x1) tmp2 += abs(y1-p[0].sc), s = 1;
    else if(p[0].fs == x2) tmp2 += abs(y2-p[0].sc), s = 2;
    else if(p[0].sc == y1) tmp2 += abs(x1-p[0].fs), s = 1;
    else if(p[0].sc == y2) tmp2 += abs(x2-p[0].fs), s = 2;

    if(p[1].fs == x1) tmp2 += abs(y1-p[1].sc), t = 1;
    else if(p[1].fs == x2) tmp2 += abs(y2-p[1].sc), t = 2;
    else if(p[1].sc == y1) tmp2 += abs(x1-p[1].fs), t = 1;
    else if(p[1].sc == y2) tmp2 += abs(x2-p[1].fs), t = 2;
    tmp2 += hypot(p[0].fs-p[1].fs,p[0].sc-p[1].sc);
    //debug(hypot(p[0].fs-p[1].fs,p[0].sc-p[1].sc));
    //cout << p[0].fs SP p[0].sc SP p[1].fs SP p[1].sc << endl;
    if(s==t) tmp2 = 1e18;
  }

  cout << fixed << min(tmp,tmp2) << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}