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

void ng(){
  cout << -1 << endl;
  exit(0);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s,t;
  cin >> n >> s >> t;

  vec cnt(26,0), id[26];
  REP(i,n){
    cnt[s[i]-'a']++, cnt[t[i]-'a']++;
    if(s[i] != t[i]) id[t[i]-'a'].push_back(i);
  }

  REP(i,26) if(cnt[i]%2) ng();

  vector<P> ans;
  REP(i,n){
    if(s[i]==t[i]) continue;
    int cur = id[t[i]-'a'].back(); id[t[i]-'a'].pop_back();
    ans.push_back(P(i+1,cur+1));
    swap(s[i],t[cur]);
    if(s[cur] != t[cur]) id[t[cur]-'a'].push_back(cur);
  }

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i].fs SP ans[i].sc << "\n";

  return 0;
}