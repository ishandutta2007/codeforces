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
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void solve(){
  int N; 
  cin >> N;
  
  vector<int> a(N);
  REP(i,N){
    cin >> a[i];
    if(a[i]%2==0) a[i] = 2-a[i];
  }
  
  vec edge[N];
  REP(_,N-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
  }

  auto f = [&](int c){
    queue<int> que[2];
    vec used(N,0),cnt(N);
    REP(i,N){
      if(edge[i].size()<2){
        if(a[i]==(c^1)) que[c^1].push(i);
        else que[c].push(i);
        used[i]++;
      }
      cnt[i] = edge[i].size()-1;
    }
    int res = 0;
    while(que[0].size()||que[1].size()){
      // cout << que[0].size() SP que[1].size() << endl;
      while(que[c].size()){
        int no = que[c].front(); que[c].pop();
        for(int to:edge[no]){
          if(used[to]) continue;
          cnt[to]--;
          if(cnt[to]!=0) continue;
          if(a[to]==(c^1)) que[c^1].push(to);
          else que[c].push(to);
          used[to]++;
        }
      }
      res++; c ^= 1;
    }
    return res;
  };

  cout << min(f(0),f(1)) << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}