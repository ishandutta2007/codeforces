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
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vec edge[1111];
vec used(1111,0);

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  REP(_,n-1){
    int x,y;
    cin >> x >> y;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  if(n==2){
    cout << "?" SP 1 SP 2 << endl;
    int x;
    cin >> x;
    cout << "!" SP x << endl;
    return 0;
  }

  int v;
  REP(i,n){
    if(edge[i].size()==1) v = i;
  }
  used[v]++;

  //debug(v);

  while(1){
    vec x = {};
    vec f(n+10,0); f[v]++;
    for(int to:edge[v]){
      if(used[to]) continue;
      x.push_back(to);
      f[to]++;
    }
    if(x.size()==0){
      cout << "!" SP v << endl;
      return 0;
    }
    else if(x.size()>=2){
      used[v] = used[x[0]] = used[x[1]] = 1; 
      cout << "?" SP x[0] SP x[1] << endl;
      cin >> v;
    }
    else{
      int t = -1;
      for(int to:edge[x[0]]){
        if(used[to]||to==v) continue;
        x.push_back(to);
        t = to;
      }
      if(t==-1){
        used[v] = used[x[0]] = 1;
        cout << "?" SP v SP x[0] << endl;
        cin >> v;
      }
      else{
        used[v] = used[x[0]] = used[t] = 1;
        cout << "?" SP v SP t << endl;
        cin >> v;        
      }
    }
  }

  return 0;
}