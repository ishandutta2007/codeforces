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
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  string s;
  int k;
  cin >> s >> k;

  int n = s.size(),cnt = 0;
  bool snow = true;
  REP(i,n){
    if(s[i] == '*' || s[i] == '?') cnt++;
    if(s[i] == '*') snow = false;
  }

  if(n-2*cnt > k || (n-cnt < k && snow)){
    cout << "Impossible" << endl;
    return 0;
  }

  string ans;
  int tmp = n-cnt-k;
  if(n-cnt >= k){
    REP(i,n){
      if(i != n-1 && (s[i+1] == '*' || s[i+1] == '?')){
        if(tmp){
          tmp--;
          i++;
        }
        else{
          ans += s[i];
          i++;
        }
      }
      else ans += s[i];
    }
  }

  else{
    bool flag = true;
    REP(i,n){
      if(flag && i != n-1 && s[i+1] == '*'){
        while(tmp != 0){
          tmp++;
          ans += s[i];
        }
        flag = false;
      }
      if(s[i] != '*' && s[i] != '?') ans += s[i];
    }
  }

  cout << ans << endl;

  return 0;
}