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
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
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
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<P> a;
int n,s;

bool check(int mid){
  int sum = 0;
  auto comp = [&](P a, P b){
    if((a.sc < mid)^(b.sc < mid)) return a.sc < b.sc;
    return a.fs < b.fs;
  } ;
  sort(a.begin(),a.end(),comp);
  REP(i,n){
    if(i<n/2) sum += a[i].fs;
    else sum += max(a[i].fs,mid);
    if(i==n/2 && mid > a[i].sc) return false;
  }
  return sum <= s;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  REP(_,t){
    cin >> n >> s;

    a.resize(n);
    REP(i,n) cin >> a[i].fs >> a[i].sc;

    int ng = 2e15, ok = 0;
    while (abs(ng-ok)>1) {
      int mid = (ng+ok)/2;
      (check(mid)?ok:ng) = mid;
    }

    cout << ok << "\n";

  }

  return 0;
}