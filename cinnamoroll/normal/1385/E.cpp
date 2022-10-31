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

struct t_sort{
  private:
  vector<int> h,ord,inv;
  vector<vector<int>> g;
  int v,e = 0;

public:
  t_sort(int N){
    h.assign(N,0);
    g.resize(N);
    inv.resize(N);
    v = N;
  }

  void add_edge(int x, int y){
    g[x].push_back(y);
    h[y]++; e++;    
  }

  void build(){
    stack<int> st;
    REP(i, v) if(h[i] == 0) st.push(i);
    while(st.size()) {
      int i = st.top(); st.pop();
      ord.push_back(i);
      for(auto& j: g[i]) {
        h[j]--;
        if(h[j] == 0) st.push(j);
      }
    }
    REP(i,ord.size()) inv[ord[i]] = i;
  }

  bool ok(){
    return ord.size() == v;
  }

  bool cmp(int x, int y){
    assert(x < v && y < v);
    return inv[x] < inv[y];
  }
};

void solve(){
  int N,M;
  cin >> N >> M;

  t_sort t(N);

  vector<P> list, list2;
  REP(i,M){
    int c,x,y;
    cin >> c >> x >> y; x--; y--;
    if(c==0) list.emplace_back(x,y);
    else{
      t.add_edge(x,y);
      list2.emplace_back(x,y);
    }
  }

  t.build();
  if(!t.ok()) cout << "NO" << endl;
  else{
    cout << "YES" << endl;
    for(P p:list){
      if(t.cmp(p.fs,p.sc)) cout << p.fs+1 SP p.sc+1 << endl;
      else cout << p.sc+1 SP p.fs+1 << endl;
    }
    for(P p:list2){
      cout << p.fs+1 SP p.sc+1 << endl;
    }
  }
}


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}