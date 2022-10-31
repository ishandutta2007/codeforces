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
#define INF (1LL<<60)
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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n; cin >> n;
    map<string,int> mp;
    vec x,y;
    vector<string> t(n);
    bool f = false, g = false;
    REP(i,n){
      string s;
      cin >> s;
      if(s[0]==s.back()){
        if(s[0] == '0') f = true;
        else g = true;
        continue;
      }
      if(s[0]=='0') x.push_back(i);
      else y.push_back(i), reverse(s.begin(),s.end());
      mp[s]++; t[i] = s;
    }
    if(!x.size()&&!y.size()&&!(f^g)) cout << -1 << "\n";
    else{
      if(x.size() < y.size()) swap(x,y);
      int m = x.size()-y.size();
      vec ans;
      REP(i,x.size()){
        if(m<=1) break;
        if(mp[t[x[i]]] < 2) ans.push_back(x[i]), m-=2;
      }
      if(m>1) cout << -1 << "\n";
      else{
        cout << ans.size() << "\n";
        REP(i,ans.size()) cout << ans[i]+1 << " ";
        cout << "\n";
      }
    }
  }

  return 0;
}