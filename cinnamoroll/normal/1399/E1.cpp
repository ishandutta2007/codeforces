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

vector<P> edge[101010];
priority_queue<P,vector<P>,function<bool(P,P)>> q([](P a, P b){return (a.fs+1)/2*a.sc < (b.fs+1)/2*b.sc;});
int sum = 0;

int dfs(int no, int par = -1){
  int cnt = 0;
  for(P to: edge[no]){
    if(to.fs==par) continue;
    int x = dfs(to.fs,no);
    q.push(P(to.sc,x));
    cnt += x;
    sum += to.sc*x;
  }
  if(edge[no].size()==1) return 1;
  else return cnt;
}

void init(int N){
  REP(i,N) edge[i].clear();
  while(q.size()) q.pop();
  sum = 0;
}

void solve(){
  int N,S;
  cin >> N >> S;
  init(N);

  REP(_,N-1){
    int x,y,c;
    cin >> x >> y >> c;
    x--; y--;
    edge[x].emplace_back(y,c);
    edge[y].emplace_back(x,c);
  }

  dfs(0);
  int ans = 0;
  while(sum > S){
    P x = q.top();
    sum -= (x.fs-x.fs/2)*x.sc;
    q.pop();
    q.push(P(x.fs/2,x.sc));
    ans++;
  }

  cout << ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}