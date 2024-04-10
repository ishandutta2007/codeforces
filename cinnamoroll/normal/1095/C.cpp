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
#define INF 1LL<<60
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
#define range(i,a,b) (a)<=(i) && (i)<(b)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,k;
  cin >> n >> k;
  
  int cnt = 0;
  vector<int> tmp(32,0);
  REP(i,32){
    if(1<<i & n){
      cnt++;
      tmp[i]++;
    }
  }

  if(cnt > k || n < k){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  RREP(i,32){
    if(tmp[i] == 0) continue;
    if(cnt == k) break;
    cnt++;
    tmp[i]--;
    tmp[i-1] += 2;
    i++;
  }

  REP(i,32){
    while(tmp[i]){
      cout << (int)pow(2,i) << " ";
      tmp[i]--;
    }
  }

  return 0;
}