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
//
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int N = 2010;
vector<int> edge[N], c(N), v;

vector<P> dfs(int no, int par){
  vector<P> res;
  for(int to: edge[no]){
    if(to==par) continue;
    vector<P> tmp = dfs(to,no);
    REP(i,tmp.size()) res.push_back(tmp[i]);
  }
  sort(res.begin(),res.end());
  if(res.size()<c[no]){
    cout << "NO" << endl;
    exit(0);
  }
  else if(res.size()==c[no]){
    if(res.size()) v[no] = res.back().fs+1;
    else v[no] = no*2222;
  }
  else{
    v[no] = res[c[no]].fs-1;
    if(c[no] && res[c[no]-1].fs==v[no]) REP(i,c[no]) res[i].fs--,v[res[i].sc]--;
  }
  res.push_back(P(v[no],no));
  return res;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  int root;
  REP(i,n){
    int x;
    cin >> x >> c[i];
    if(x==0){
      root = i;
      continue;
    }
    x--;
    edge[x].emplace_back(i);
    edge[i].emplace_back(x);
  }

  v.resize(n);

  dfs(root,-1);

  int mn = INF;
  REP(i,n) mn = min(mn,v[i]);

  cout << "YES" << endl;
  REP(i,n) cout << v[i]-mn+1 << " ";


  return 0;
}