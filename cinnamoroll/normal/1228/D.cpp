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
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
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
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void ng(){
  cout << -1 << endl;
  exit(0);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<int> edge[n];
  set<P> st;
  REP(_,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
    st.insert(P(x,y));
    st.insert(P(y,x));
  }

  int id = 0;
  vec list[3];
  vector<int> flag(n,0);
  REP(i,n){
    if(flag[i]) continue;
    vec now(n,0);
    for(int no:edge[i]) now[no]++;
    REP(j,n) if(flag[j]==0&&now[j]==0) list[id].push_back(j), flag[j]++;
    id++;
    if(id==3) break;
  }

  if(id!=3) ng();
  REP(i,n) if(flag[i]==0) ng();
  if(list[0].size()*list[1].size()+list[2].size()*list[1].size()+list[0].size()*list[2].size() != m) ng();

  REP(i,3){
    int j = (i+1)%3;
    for(int no:list[i]){
      for(int to:list[j]) if(st.find(P(no,to))==st.end()) ng();
    }
  }

  vec ans(n,0);
  REP(i,3){
    for(int k:list[i]) ans[k] = i+1;
  }

  REP(i,n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}