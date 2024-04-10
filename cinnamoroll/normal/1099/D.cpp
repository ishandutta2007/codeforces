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

const int NMAX = 1e5;
vector<int> edge[NMAX],s(NMAX);
vector<int> ans(NMAX,0);
bool check = true;

int dfs(int no, int sum){
  int cnt = 0, mn = INF;
  if(s[no] != -1) REP(i,edge[no].size()) dfs(edge[no][i],sum);
  else {
    REP(i,edge[no].size()){
      mn = min(mn,s[edge[no][i]]);
    }
    //cout << no SP mn SP sum << endl;
    if(mn-sum < 0){
      check = false;
      return 0;
    }

    if(mn == INF) ans[no] = 0;
    else ans[no] = mn-sum;
    
    REP(i,edge[no].size()){
      ans[edge[no][i]] = s[edge[no][i]] - mn;
      dfs(edge[no][i],s[edge[no][i]]);
    }
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  cin >> n;

  vector<int> p(n-1);
  REP(i,n-1) cin >> p[i];

  REP(i,n-1) edge[p[i]-1].pb(i+1);
  
  REP(i,n) cin >> s[i];
  
  ans[0] = s[0];
  dfs(0,s[0]);

  if(!check) cout << -1 << endl;

  else cout << accumulate(ans.begin(),ans.end(),0LL) << endl;

  return 0;
}