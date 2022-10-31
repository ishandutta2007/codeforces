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

const int N = 2e5+10;
int n,m;

bool check(int mid, vec &a, vector<P> &b){
  int sum = accumulate(a.begin(),a.end(),0LL);
  vec flag(n,0);
  REP(i,m){
    if(b[i].fs > mid) break;
    flag[b[i].sc] = b[i].fs;
  }
  priority_queue<P,vector<P>,greater<P>> que;
  que.push(P(INF,INF));
  REP(i,n) if(flag[i]) que.push(P(flag[i],i));

  int cur = 0, get = 0;
  FOR(i,1,mid+1){
    cur++;
    while(que.top().fs == i){
      int tmp = min(a[que.top().sc],cur);
      get += tmp;
      cur -= tmp;
      que.pop();
    }
  }
  return get + cur/2 >= sum;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<P> b(m);
  REP(i,m) cin >> b[i].fs >> b[i].sc, b[i].sc--;

  sort(b.begin(),b.end());

  int ng = 0, ok = 4e5+10;
  while (abs(ng-ok)>1) {
    int mid = (ng+ok)/2;
    (check(mid,a,b)?ok:ng) = mid;
  }

  cout << ok << endl;

  return 0;
}