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
typedef pair<string,string> Q;
typedef pair<int,string> R;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  char c[] = {'a','i','u','e','o'};

  vector<tuple<int,int,string>> s(n);
  REP(i,n){
    string t;
    cin >> t;
    int ch = 5, cnt = 0;
    REP(j,t.size()){
      REP(k,5) if(t[j] == c[k]) cnt++, ch = k;
    }
    s[i] = tie(cnt,ch,t);
  }
  
  sort(s.begin(),s.end());

  int cur = -1;
  stack<string> st[6];
  vector<Q> ans, ans2;
  REP(i,n+1){//debug(i);
    int x,y; string t;
    if(i != n) tie(x,y,t) = s[i];
    if(x != cur || i == n){
      REP(j,5) if(st[j+1].size()) st[0].push(st[j+1].top()), st[j+1].pop();
      while(st[0].size() >= 2){
        string u,v;
        u = st[0].top(); st[0].pop();
        v = st[0].top(); st[0].pop();
        ans2.push_back(Q(u,v));
      }
      if(st[0].size()) st[0].pop();
      if(i == n) break;
      cur = x;
    }
//debug(i); cout << x SP y SP t << endl;
    if(st[y].size()) ans.push_back(Q(t,st[y].top())), st[y].pop();
    else st[y].push(t);
    
  }

  //debug(ans.size());
  //debug(ans2.size());

  vector<Q> res;
  int m = min(ans.size(),ans2.size());

  REP(i,m) res.push_back(ans2[i]), res.push_back(ans[i]);
  FOR(i,m,ans.size()) res.push_back(ans[i]);

  m = res.size()/2;
  cout << m << endl;

  REP(i,m){
    cout << res[i*2].fs SP res[i*2+1].fs << endl;
    cout << res[i*2].sc SP res[i*2+1].sc << endl;
  }

  return 0;
}