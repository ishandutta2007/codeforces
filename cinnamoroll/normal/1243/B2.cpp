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
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void ng(){
  cout << "No" << "\n";
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int q;
  cin >> q;
 
  REP(_,q){
    int n;
    string s,t;
    cin >> n >> s >> t;
 
    vec cnt(26,0);
    REP(i,n) cnt[s[i]-'a']++, cnt[t[i]-'a']++;
    bool flag = false;
    REP(i,26) if(cnt[i]%2) flag = true;
    if(flag) {ng(); continue;}
    vector<P> ans;
    REP(i,n-1){
      FOR(j,i+1,n) if(s[i]==s[j]){
        swap(s[j],t[i]); ans.emplace_back(j+1,i+1);
        goto nx;
      }
      FOR(j,i,n) if(s[i]==t[j]){
        swap(s[i+1],t[j]); swap(s[i+1],t[i]);
        ans.emplace_back(i+2,j+1); ans.emplace_back(i+2,i+1);
        goto nx;
      }
      nx:;
    }
    cout << "Yes" << "\n" << ans.size() << "\n";
    for(P p:ans) cout << p.fs SP p.sc << "\n";
  }
 
  return 0;
}