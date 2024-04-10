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

vector<int> a(N);
vector<int> b(N);

int n;

bool check2(int mid){
  vec flag(n+1,0);
  REP(i,n) flag[a[i]]++;
  int k = n-mid;
  REP(i,k) if(b[n-k+i] != i+1) return false;

  REP(i,mid){
    if(flag[i+1+k] == 0) return false;
    flag[b[(mid+i+k)%n]]++;
   // debug(b[(mid+i)%n]);
  }
  return true;
}

bool check(int mid){
  //if(mid < n) return check2(mid);
  mid -= n;
  vec flag(n+1,0);
  REP(i,n) flag[a[i]]++;
  REP(i,mid) flag[b[i]]++;

  REP(i,n){
    //debug(i);
    if(flag[i+1] == 0) return false;
    flag[b[(mid+i)%n]]++;
    //debug(b[(mid+i)%n]);
  }
  return true;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  REP(i,n) cin >> a[i];
  
  REP(i,n) cin >> b[i];

  int cnt = b[n-1];
  bool f = true;
  RREP(i,n){
    if(b[i] != cnt) f = false;
    cnt--;
    if(cnt == 0) break;
  }

  if(f){
    int ans = n-b[n-1];
    if(b[0] == b[n-1]+1) goto out;
    REP(i,n-b[n-1]){
      //cout << i << endl;
      if(b[i] && b[i]-b[n-1]-2 < i) goto out;
    }
    cout <<  ans << endl;
    return 0;
  }
  out:;

  int ng = n-1, ok = 2*n;
  while (abs(ng-ok)>1) {
    int mid = (ng+ok)/2;
    //debug(mid);
    (check(mid)?ok:ng) = mid;
  } 
  
  cout << ok << endl;

  return 0;
}