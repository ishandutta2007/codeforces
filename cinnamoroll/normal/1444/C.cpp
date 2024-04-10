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
 
struct UnionFind {
  private:
  vector<int> par,sz;
  vector<tuple<int,int,int>> memo;
  vector<vector<int>> list;
 
public:
  UnionFind(int v) {
    par.resize(v);
    sz.resize(v);
    REP(i,v){
      par[i] = i;
      sz[i] = 1;
    }
  }
 
  int root(int no){
    if(par[no]==no) return no;
    else return root(par[no]);
  }
 
  int size(int i){
    return sz[i];
  }

  vector<int> nodes(int no){
    assert(false); // undo
    return list[root(no)];
  }
 
  bool unit(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y) return false;
    if(sz[x] < sz[y]) swap(x,y);
    memo.emplace_back(x,y,par[y]);
    // for(int no:list[y]) list[x].emplace_back(no);
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
 
  bool isUnit(int x, int y){
    return root(x) == root(y);
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
  int N,M,K;
  cin >> N >> M >> K;
  
  vector<int> a(N);
  REP(i,N) cin >> a[i], a[i]--;
  
  set<P> st;
  vector<P> e[M]; int id = 0;
  
  map<P,int> mp,f; UnionFind uf(2*N);
  REP(_,M){
    int x, y;
    cin >> x >> y;
    x--; y--;
    int u = a[x], v = a[y];
    if(u > v) swap(u,v), swap(x,y);
    if(u!=v){
      st.insert(P(u,v));
      if(!mp.count(P(u,v))) mp[P(u,v)] = id++;
      e[mp[P(u,v)]].emplace_back(x,y);
    }
    else{
      uf.unit(x*2,y*2+1);
      uf.unit(x*2+1,y*2);
    }
  }
 
  int ans = K*(K-1)/2; vec ng(K,0);
  REP(i,N) if(uf.isUnit(i*2,i*2+1)) ng[a[i]]++;
 
  int cnt = K-1;
  REP(i,K) if(ng[i]) ans -= cnt, cnt--;
 
  //debug(ans);
 
  ITR(itr,st){
    int x = itr->fs, y = itr->sc;
    //cout << x SP y << endl;
    if(ng[x]||ng[y]) continue;
    int t = uf.time();
    for(P E:e[mp[P(x,y)]]){
      if(uf.unit(E.fs*2,E.sc*2+1)) cnt++;
      if(uf.unit(E.fs*2+1,E.sc*2)) cnt++;
      if(uf.isUnit(E.fs*2,E.fs*2+1)){
        ans--; break;
      }
    }
    uf.undo(t);
    //debug(ans);
  }
 
  cout << ans << endl;
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T = 1;
  // cin >> T;
 
  while(T--) solve();
 
  return 0;
}