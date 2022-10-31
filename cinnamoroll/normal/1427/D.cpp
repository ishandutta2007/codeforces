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
  REP(i,N) cin >> a[i], a[i]--;

  mat ans;
  
  REP(i,N){
    int t = (N-i)%2;
    vec d;
    if(t){
      int id;
      REP(j,N) if(a[j]==i) id = j;
      if(id) d.push_back(id);
      d.push_back(N-id-i);
      REP(j,i) d.push_back(1);
    }
    else{
      //i
      REP(j,i) d.push_back(1);
      int id;
      FOR(j,i,N) if(a[j]==i) id = j;
      //debug(id);
      d.push_back(id-i+1);
      if(N-id-1) d.push_back(N-id-1);
    }
    
    bool flag = true;
    REP(j,d.size()) if(d[j]==0) flag = false;
    if(flag && d.size()>1) ans.push_back(d);
    else continue;

    vec b; int in = 0;
    REP(j,d.size()){
      vec c;
      REP(k,d[j]) c.push_back(a[in+k]);
      REP(k,b.size()) c.push_back(b[k]);
      b = c;
      in += d[j];
    }
    //REP(i,N) cout << b[i] << " "; cout << endl;
    a = b;
  }

  cout << ans.size() << endl;
  REP(i,ans.size()){
    cout << ans[i].size() << " ";
    REP(j,ans[i].size()) cout << ans[i][j] << " "; cout << endl;
  }

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}