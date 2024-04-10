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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //

  string s;
  cin >> s;

  int n = s.size();

  vector<string> t(3);
  REP(i,n){
    int tmp = i;
    REP(j,3){
      t[j] += (char)('a'+ (tmp%26));
      tmp /= 26;
    }
  }

  vector<int> in(n,0);

    cout << "?" SP t[0] << endl;
    cout.flush();
    string u;
    cin >> u;
    REP(i,n) in[i] += u[i]-'a';

    cout << "?" SP t[1] << endl;
    cout.flush();
    cin >> u;
    REP(i,n) in[i] += (u[i]-'a')*26;

    cout << "?" SP t[2] << endl;
    cout.flush();
    cin >> u;
    REP(i,n) in[i] += (u[i]-'a')*26*26;

  REP(i,n) u[in[i]] = s[i];

  cout << "!" SP u << endl;
  cout.flush();

  return 0;
}