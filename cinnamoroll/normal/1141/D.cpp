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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s,t;
  cin >> n >> s >> t;

  queue<int> cnt1[27], cnt2[27];
  REP(i,n){
    if(s[i] == '?') cnt1[26].push(i);
    else cnt1[s[i]-'a'].push(i);
    if(t[i] == '?') cnt2[26].push(i);
    else cnt2[t[i]-'a'].push(i);    
  }

  vector<P> ans;
  REP(i,26){
    while(cnt1[i].size() && cnt2[i].size()){
      int x = cnt1[i].front(); cnt1[i].pop();
      int y = cnt2[i].front(); cnt2[i].pop();
      ans.push_back(P(x,y));
    }
  }

  int id = 0;
  while(cnt1[26].size()){
    while(id < 26 && cnt2[id].size() == 0) id++;
    if(id == 26) break;
    int x = cnt1[26].front(); cnt1[26].pop();
    int y = cnt2[id].front(); cnt2[id].pop();
    ans.push_back(P(x,y));
  }
  
  id = 0;
  while(cnt2[26].size()){
    while(id < 26 && cnt1[id].size() == 0) id++;
    if(id == 26) break;
    int x = cnt1[id].front(); cnt1[id].pop();
    int y = cnt2[26].front(); cnt2[26].pop();
    ans.push_back(P(x,y));
  }

  while(cnt1[26].size() && cnt2[26].size()){
    int x = cnt1[26].front(); cnt1[26].pop();
    int y = cnt2[26].front(); cnt2[26].pop();
    ans.push_back(P(x,y));
  }

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i].fs+1 SP ans[i].sc+1 << endl;

  return 0;
}