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
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
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

double det(P x,P y){
  return x.fs*y.sc-x.sc*y.fs;
}
P sub(P x,P y){
  return P(x.fs-y.fs, x.sc-y.sc);
}

vector<P> Convex_Hull(vector<P>& p){
  int n = p.size(), k = 0;
  sort(p.begin(),p.end());
  vector<P> q(2*n);
  //
  REP(i,n){
    while(k > 1 && det(sub(q[k-1],q[k-2]),sub(p[i],q[k-1])) <= 0) k--;
    q[k++] = p[i];
  }
  //
  int t = k;
  RREP(i,n-1){
    while(k > t && det(sub(q[k-1],q[k-2]),sub(p[i],q[k-1])) <= 0) k--;
    q[k++] = p[i];
  }
  q.resize(k-1);
  return q;
}

int N;
double p,q;
bool check(double mid, vector<P> a){
  REP(i,a.size()) a[i].fs *= mid, a[i].sc *= mid;
  a.push_back(P(p,q));
  auto b = Convex_Hull(a);
  for(P r:b){
    //cout << fixed << r.fs SP r.sc << endl;
    if(r == P(p,q)) return false;
  }
  return true;
}

void solve(){
  
  cin >> N >> p >> q;

  vector<P> a(N+1,P(0,0));
  REP(i,N) cin >> a[i].fs >> a[i].sc;

  double ng = 0, ok = 1000000;
  REP(_,44){
    double mid = ng+(ok-ng)/2;
    //debug(mid);
    (check(mid,a)?ok:ng) = mid;
  }

  REP(i,N) chmin(ok,max(p/a[i].fs,q/a[i].sc));

  cout << fixed << ok << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}