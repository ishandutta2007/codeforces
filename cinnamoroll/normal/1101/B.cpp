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
  cin >> s;

  int ans = 0;
  int op = -1, cl = -1, l = -1, r = -1;
  REP(i,s.size()){
    if(op == -1){
      if(s[i] == '[') op = i;
      else ans++;
    }
    else if(l == -1){
      if(s[i] == ':') l = i;
      else ans++;
    }
  }

  RREP(i,s.size()){
    if(cl == -1){
      if(s[i] == ']') cl = i;
      else ans++;
    }
    else if(r == -1){
      if(s[i] == ':') r = i;
      else ans++;
    }
  }

  if(op == -1 || cl == -1 || op > cl || l >= r || l == -1 || r == -1){
    cout << -1 << endl;
    return 0;
  }

  FOR(i,l+1,r){
    if(s[i] != '|') ans++;
  }

  cout << s.size()-ans << endl;

  return 0;
}