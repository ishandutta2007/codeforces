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
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

vector<int> child;
int root(vector<int>& tree, int i){
  if(i == tree[i]){
    REP(j,child.size()) tree[child[j]] = i;
    child.clear(); 
    return i;
  }
  else{
    child.push_back(i);
    return i = root(tree,tree[i]);
  }
}

int unit(vector<int>& tree, int x, int y){
  x = root(tree,x);
  y = root(tree,y);
  tree[max(x,y)] = min(x,y);
}

bool isUnit(vector<int>& tree, int x, int y){
  return root(tree,x) == root(tree,y);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  int id;
  int mn = INF;
  REP(i,n){
    cin >> a[i];
    if(mn > a[i]){
      mn = a[i];
      id = i;
    }
  }
  
  vector<tuple<int,int,int>> edge(m);
  REP(i,m){
    int a,b,w;
    cin >> a >> b >> w;
    edge[i] = make_tuple(w,a-1,b-1);
  }

  REP(i,n){
    if(id == i) continue;
    edge.pb(make_tuple(a[i]+a[id],i,id));
  }

  sort(edge.begin(),edge.end());

  vector<int> tree(n);
  REP(i,n) tree[i] = i;

  int ans = 0;
  REP(i,n+m-1){
    if(isUnit(tree,get<1>(edge[i]),get<2>(edge[i]))) continue;
    unit(tree,get<1>(edge[i]),get<2>(edge[i]));
    ans += get<0>(edge[i]);
  }

  cout << ans << endl;

  return 0;
}