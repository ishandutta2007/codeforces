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
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define D double
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
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    string s,t,p;
    cin >> s >> t >> p;

    int n = t.size(), id = 0;
    vec cnt(26,0);
    REP(i,n){
      if(id == s.size() || t[i] != s[id]){
        cnt[t[i]-'a']++;
      }
      else id++;
    }

    REP(i,p.size()) cnt[p[i]-'a']--;
    bool flag = true;
    REP(i,26) if(cnt[i] > 0) flag = false;

    if(flag && id == s.size()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }

  return 0;
}