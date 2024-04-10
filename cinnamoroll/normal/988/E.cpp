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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int ans = 1000, n = s.size();
  vec cnt(10,0);
  REP(i,s.size()) cnt[s[i]-'0']++;

  if(cnt[0]>=2){
    int cur = 0, tmp = 2;
    RREP(i,n){
      if(s[i]=='0') cur += n-i-1, tmp--;
      if(tmp == 0) break;
    }
    ans = min(ans,cur);
  }

  if(cnt[2] && cnt[5]){
    int cur = 0, two = 100, five = 100;
    REP(i,n){
      if(s[i] == '2') two = n-1-i;
      if(s[i] == '5') five = n-1-i;
    }
    cur = two + five;
    if(two < five) cur++,swap(two,five);
    string t = s;
    RREP(i,five) swap(t[n-1-i],t[n-2-i]);
    RREP(i,two-1) swap(t[n-3-i],t[n-2-i]);
    REP(i,n){
      if(t[i]=='0') cur++;
      else break;
    }
    ans = min(ans,cur);
  }

  if(cnt[0] && cnt[5]){
    int cur = 0, two = 100, five = 100;
    REP(i,n){
      if(s[i] == '0') two = n-1-i;
      if(s[i] == '5') five = n-1-i;
    }
    cur = two + five;
    if(two > five) cur++;
    ans = min(ans,cur);
  }

  if(cnt[7] && cnt[5]){
    int cur = 0, two = 100, five = 100;
    REP(i,n){
      if(s[i] == '7') two = n-1-i;
      if(s[i] == '5') five = n-1-i;
    }
    cur = two + five;
    if(two < five) cur++,swap(two,five);
    string t = s;
    RREP(i,five) swap(t[n-1-i],t[n-2-i]);
    RREP(i,two-1) swap(t[n-3-i],t[n-2-i]);
    REP(i,n){
      if(t[i]=='0') cur++;
      else break;
    }
    ans = min(ans,cur);
  }

  if(ans != 1000) cout << ans-1 << endl;
  else cout << -1 << endl;

  return 0;
}