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

const int NMAX = 1e6;
vector<int> child,tree(NMAX);
int root(int i){
  if(i == tree[i]){
    REP(j,child.size()) tree[child[j]] = i;
    child.clear(); 
    return i;
  }
  else{
    child.push_back(i);
    return i = root(tree[i]);
  }
}

int unit(int x, int y){
  x = root(x);
  y = root(y);
  tree[max(x,y)] = min(x,y);
}

bool isUnit(int x, int y){
  return root(x) == root(y);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,m;
  cin >> n >> m;

  vector<pair<int,P>> edge(m);
  REP(i,m){
    int x,y,cost;
    cin >> x >> y >> cost;
    edge[i] = make_pair(cost,P(x-1,y-1));
  }

  sort(edge.begin(),edge.end());
  int ans = 0, cur = 0;
  REP(i,n) tree[i] = i;
  int i = 0;
  while(i<m){
    cur = edge[i].fs;
    vector<P> tmp;
    while(i<m && cur == edge[i].fs){
      if(!isUnit(edge[i].sc.fs,edge[i].sc.sc)) tmp.pb(P(edge[i].sc.fs,edge[i].sc.sc));
      i++;
    }
    bool flag = false;
    int cnt = 0;
    for(auto to:tmp){
      if(isUnit(to.fs,to.sc)) cnt++;
      else unit(to.fs,to.sc), flag = true;  
    }
    if(flag) ans += cnt;
  }

  cout << ans << endl;

  return 0;
}