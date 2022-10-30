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
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
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

  int h,w;
  cin >> h >> w;

  vector<string> s(h);
  REP(i,h) cin >> s[i];
  
  int cnt = 0;
  REP(i,h) REP(j,w) if(s[i][j] == '*') cnt++;

  REP(i,h){
    REP(j,w){
      if(s[i][j] == '.') continue;
      int tmp = 1;
      bool f = true;
      RFOR(k,0,i){
        if(s[k][j] == '*') tmp++, f = false;
        else break;
      }
      if(f) goto out;
      f = true;
      FOR(k,i+1,h){
        if(s[k][j] == '*') tmp++, f = false;
        else break;
      }
      if(f) goto out;
      f = true;
      RFOR(k,0,j){
        if(s[i][k] == '*') tmp++, f = false;
        else break;
      }
      if(f) goto out;
      f = true;
      FOR(k,j+1,w){
        if(s[i][k] == '*') tmp++, f = false;
        else break;
      }     
      if(f) goto out;
      //debug(tmp);
      if(cnt == tmp){
        cout << "YES" << endl;
        return 0;
      }
      out:;
    }
  }

  cout << "NO" << endl;

  return 0;
}