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

void solve(){
  int N; string S;
  cin >> N >> S;

  mat nx(2,vec(N+1,0));
  vec a[2][N+1];
  RREP(i,N){
    if(S[i]!='0') nx[0][i] = nx[0][i+1]+1;
    if(S[i]!='1') nx[1][i] = nx[1][i+1]+1;
  }

  REP(x,2){
    int l = 0, r = 0;
    while(l < N){
      while(l < N && S[l]-'0'==1-x) l++;
      r = l;
      while(r<N && S[r]-'0'!=1-x) r++;
      FOR2(i,1,r-l) a[x][i].push_back(l);
      l = r;
    }
  }

  // REP(i,N) cout << nx[0][i] SP nx[1][i] << endl;

  // REP(i,N){
  //   debug(i);
  //   REP(j,2){
  //     for(int x:a[j][i+1]) cout << x << " ";
  //     cout << endl;
  //   }
  // }

  // debug(N);

  FOR2(i,1,N){
    //debug(i);
    int now = 0, ans = 0;
    int id[2] = {};
    while(now < N){
      //debug(now);
      int nxt = INF;
      REP(j,2){
        if(nx[j][now]>=i) nxt = now+i;
        while(id[j]<a[j][i].size() && now > a[j][i][id[j]]) id[j]++;
        if(id[j] < a[j][i].size()) chmin(nxt,a[j][i][id[j]]+i);
      }
      if(nxt==INF) break;
      ans++; now = nxt;
    }
    cout << ans << " ";
  }

  cout << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}