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
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vec z_algorithm(string& s){
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
  //
  //
  //DP

  string s,t;
  cin >> s >> t;

  vec cnt(2);
  REP(i,s.size()) cnt[s[i]-'0']++;

  //
  vec z = z_algorithm(t);
  string tmp = t; //1t
  FOR(i,1,t.size()){
    if(z[i] == t.size()-i){
      tmp = t.substr(t.size()-i,i);
      break;
    }
  }

  string ans;
  REP(i,t.size()){
    if(cnt[t[i]-'0']){
      ans += t[i];
      cnt[t[i]-'0']--;
    }
    else{
      cout << s << endl;
      return 0;
    }
  }

  bool flag = true;
  while(flag){
    REP(i,tmp.size()){
      if(cnt[tmp[i]-'0']){
        ans += tmp[i];
        cnt[tmp[i]-'0']--;
      }
      else flag = false;
    }
  }

  REP(i,2) while(cnt[i]) ans += (char)('0'+i), cnt[i]--;

  cout << ans << endl;

  return 0;
}