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
#define parity(i,j) (1&(i>>j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

struct UnionFind {
  private:
  vector<int> par,sz;
  vector<tuple<int,int,int>> memo;
  vector<vector<int>> list;
 
public:
  UnionFind(int v) {
    par.resize(v);
    sz.resize(v);
    list.resize(v);
    REP(i,v){
      par[i] = i;
      sz[i] = 1;
      list[i].emplace_back(i);
    }
  }
 
  int root(int no){
    if(par[no]==no) return no;
    else return root(par[no]);
  }
 
  int size(int i){
    return sz[root(i)];
  }

  vector<int> nodes(int no){
    assert(false); // undo
    return list[root(no)];
  }
 
  int unit(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y) return -1;
    if(sz[x] < sz[y]) swap(x,y);
    memo.emplace_back(x,y,par[y]);
    // for(int no:list[y]) list[x].emplace_back(no);
    sz[x] += sz[y];
    par[y] = x;
    return x;
  }
 
  bool same(int x, int y){
    return root(x)==root(y);
  }
 
  bool undo(int t = -1){
    if(memo.empty()) return false;
    if(t==-1) t = memo.size()-1;
    while(memo.size() > t){
      int x,y,v;
      tie(x,y,v) = memo.back();
      memo.pop_back();
      sz[x] -= sz[y];
      par[y] = v;
    }
    return true;
  }

  int time(){
    return memo.size();
  }
};

void solve(){
  int N,M;
  cin >> N >> M;

  UnionFind uf(N);
  vec edge[N]; int cnt = 0;
  REP(_,M){
    int x,y;
    cin >> x >> y;
    x--; y--;      edge[x].emplace_back(y);
      edge[y].emplace_back(x);
    if(~uf.unit(x,y)){
      cnt++;
    }
  }

  if(cnt != N-1){
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;

  vec ans = {0}, d(N,0), f(N,0);
  d[0] = f[0] = 1; queue<int> que; que.push(0);

  while(que.size()){
    int no = que.front(); que.pop();
    if(f[no]){
      for(int to:edge[no]){
        if(d[to]) continue; 
        que.push(to);
        d[to]++;
      }
    }
    else{
      for(int to:edge[no]){
        if(d[to]) continue;
        d[to]++; f[to]++; ans.emplace_back(to);
        for(int to2:edge[to]){
          if(d[to2]) continue; 
          que.push(to2);
          d[to2]++;
        }
      }
    }
  }

  sort(ans.begin(),ans.end());

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i] + 1 << " ";
  cout << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}