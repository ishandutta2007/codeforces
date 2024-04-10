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

const int NMAX = 2e5;
vector<int> edge[NMAX],used(NMAX,0);
map<int,int> mp[NMAX];

int ans = 0;

void dfs(int no){
  used[no]++;
  for(auto to:edge[no]){
    if(used[to]) continue;
    dfs(to);
    for(auto &e:mp[no]){
      int tmp = mp[to][e.fs];
      ans = max(ans,tmp+e.sc);
      if(tmp >= e.sc) e.sc = tmp+1;
    }
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  REP(_,n-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].pb(y);
    edge[y].pb(x);
  }

  REP(no,n){
    FOR(i,2,500){
      if(a[no] == 1) break;
      if(a[no] % i != 0) continue;
      mp[no][i]++;
      while(a[no] % i == 0) a[no] /= i;
    }
    if(a[no] != 1) mp[no][a[no]]++;
  }

  dfs(0);

  cout << ans << endl;

  return 0;
}