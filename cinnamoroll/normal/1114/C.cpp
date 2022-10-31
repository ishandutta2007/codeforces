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

  int n,k;
  cin >> n >> k;

  int tmp = k;
  map<int,int> mp;
  for(int i=2;i<=sqrt(tmp);i+=2){
    bool flag = true;
      for(int j=3; j<=sqrt(i);j+=2){
      if(i%j == 0){
      flag = false;
      break;
      }
    }
    if(flag || i == 2){
      if(tmp%i == 0){
        int cnt = 0;
        while(tmp%i == 0) cnt++,tmp/=i;
        mp[i] = cnt;
      }
    }
    if(i == 2) i--;
  }
  //debug(mp.size());
  if(tmp != 1) mp[tmp]++;

  map<int,int> num;
  ITR(itr,mp){
    //debug(itr->fs);
    int x = n/itr->fs;
    num[itr->fs] += x;
    while(x){
      x /= itr->fs;
      num[itr->fs] += x;
    }
    //debug(num[itr->fs]);
  }

  int ans = INF;
  ITR(itr,num) ans = min(ans,itr->sc/mp[itr->fs]);

  if (num.size() == 0) cout << 0 << endl;
  else cout << ans << endl;

  return 0;
}