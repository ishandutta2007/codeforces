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

  string s;
  cin >> s;

  int n = s.size();
  vector<int> c(26,0);
  REP(i,n) c[s[i]-'a']++;

  int ppp = 0;
  bool flag = false;
  REP(i,26){
    if(c[i]) ppp++;
    if(c[i] == 1) flag = true;
  }

  if(ppp == 1 || (ppp == 2 && flag)){
    cout << "Impossible" << endl;
    return 0;
  }

  if(n % 2 == 0){
    string t = s.substr(0,n/2);
    string u = s.substr(n/2,n/2);
    if(t == u){
      bool h = false;
      while(t.size() % 2 == 0){
        string v = t.substr(0,t.size()/2);
        string w = t.substr(t.size()/2,t.size()/2);
        t = v;
        if(w == v) continue;
        else{ h = true;break;}
      }
      if(h) cout << 1 << endl;
      else cout << 2 << endl;
    }
    else cout << 1 << endl;
  }
  else cout << 2 << endl;

  return 0;
}