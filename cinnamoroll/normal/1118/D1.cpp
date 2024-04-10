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
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
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

int n,m;
bool check(int mid,vector<int> &a){
  int pos = 0;
  int cnt = 0;
  int id = 0;
  while(id < n && a[id]-cnt > 0){
    REP(_,mid){
      if(id < n && a[id]-cnt > 0) pos += a[id]-cnt;
      else break;
      id++;
    }
    cnt++;
  }
  return pos >= m;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  cin >> n >> m;

  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());

  int sum = accumulate(a.begin(),a.end(),0LL);
  if(sum < m) {cout << -1 << endl; return 0;}

  int ng = 0, ok = n;
  while (abs(ng-ok)>1) {
    int mid = (ng+ok)/2;
    (check(mid,a)?ok:ng) = mid;
  } 

  cout << ok << endl;

  return 0;
}