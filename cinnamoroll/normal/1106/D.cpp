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
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

const int NMAX = 2e5;
vector<int> edge[NMAX];
vector<int> used(NMAX,0);


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  int n,m;
  cin >> n >> m;

  REP(_,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].pb(y);
    edge[y].pb(x);
  }

  vector<int> ans;
  priority_queue<int,vector<int>,greater<int>> que;
  que.push(0);
  used[0]++;

  while(!que.empty()){
    int no = que.top();
    que.pop();
    ans.pb(no+1);
    for(int to:edge[no]){
      if(used[to]) continue;
      que.push(to);
      used[to]++;
    }
  }

  REP(i,n) cout << ans[i] << " ";

  return 0;
}