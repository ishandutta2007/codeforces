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

//SSiT
vector<int> z_algorithm(string& s){
  int n = s.size(), c = 0;
  vec ret(n);
  FOR(i,1,n){
    if(i+ret[i-c] < c + ret[c]) ret[i] = ret[i-c];
    else{
      int j = max(0LL,c+ret[c]-i);
      while(i+j < n && s[j] == s[i+j]) j++;
      ret[i] = j;
      c = i;
    }
  }
  ret[0] = n;
  return ret;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> s(n);
  REP(i,n) cin >> s[i];
  
  string ans = s[0];
  FOR(i,1,n){
    string tmp;
    if(s[i].size() > ans.size()){
      tmp = s[i].substr(0,ans.size())+ans;
      vec now = z_algorithm(tmp);
      int mx = 0;
      REP(j,ans.size()){
        if(now[tmp.size()-1-j] == j+1) mx = max(mx,j+1);
      }
      ans += s[i].substr(mx,s[i].size());
    }
    else{
      tmp = s[i]+ans.substr(ans.size()-s[i].size(),s[i].size());
      vec now = z_algorithm(tmp);
      //REP(j,now.size()) cout << now[j] << " ";
      //cout << endl;
      int mx = 0;
      REP(j,s[i].size()){
        if(now[tmp.size()-1-j] == j+1) mx = max(mx,j+1);
      }
      //debug(mx);
      ans += s[i].substr(mx,s[i].size());
    }
    //debug(tmp);
  } 

  cout << ans << endl;

  return 0;
}