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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  int n,m,k;
  cin >> n >> m >> k;

  vector<P> a(n);
  REP(i,n) cin >> a[i].fs, a[i].sc = i;
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());

  int sum = 0;
  vector<int> flag(n,0);
  REP(i,k*m) sum += a[i].fs;
  FOR(i,k*m,n) flag[a[i].sc]++;


  cout << sum << endl;
  int cnt = 0,id = 0;
  REP(i,n){
    if(flag[i] == 0) cnt++;
    if(cnt == m){
      cout << i+1 << " ";
      cnt = 0;
      id++;
    }
    if(id == k-1) break;
  }

  return 0;
}