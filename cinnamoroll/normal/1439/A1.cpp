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
  int N,M;
  cin >> N >> M;

  vector<string> S(N);
  REP(i,N) cin >> S[i];

  mat a(N,vec(M));
  REP(i,N) REP(j,M) a[i][j] = S[i][j]-'0';
  
  vector<P> ans;
  auto f = [&](int x, int y){
    int cnt = 0;
    vector<P> zero, one;
    REP(i,2) REP(j,2){
      if(a[x+i][y+j]) cnt++, one.emplace_back(x+i,y+j);
      else zero.emplace_back(x+i,y+j);
    }
    if(cnt==3){
      for(P p:one){
        a[p.fs][p.sc] = 0;
        ans.emplace_back(p);
      }
    }
    if(cnt==1){
      REP(i,2){
        a[zero[i].fs][zero[i].sc] = 1;
        ans.emplace_back(zero[i].fs,zero[i].sc);
      }
      REP(i,1){
        a[one[i].fs][one[i].sc] = 0;
        ans.emplace_back(one[i].fs,one[i].sc);       
      }
    }
    if(cnt==2){
      REP(i,2){
        a[zero[i].fs][zero[i].sc] = 1;
        ans.emplace_back(zero[i].fs,zero[i].sc);
      }
      REP(i,1){
        a[one[i].fs][one[i].sc] = 0;
        ans.emplace_back(one[i].fs,one[i].sc);       
      }
    }
    if(cnt==4){
      REP(i,3){
        a[one[i].fs][one[i].sc] = 0;
        ans.emplace_back(one[i].fs,one[i].sc);       
      }
    }
    return;
  };

  for(int i = 0; i+1 < N; i+=2){
    ///debug(i);
    REP(j,M-2){
      if(!a[i][j]&&!a[i+1][j]) continue;
      if(a[i][j]) ans.emplace_back(i,j) , a[i][j] ^= 1;
      if(a[i+1][j]) ans.emplace_back(i+1,j), a[i+1][j] ^= 1;
      ans.emplace_back(i,j+1); a[i][j+1] ^= 1;
      if(ans.size()%3) ans.emplace_back(i+1,j+1), a[i+1][j+1] ^= 1;
    }
    //debug(ans.size());
    REP(_,4) f(i,M-2);
    if(N%2 && i==0) i--;
    //  debug(ans.size());
  }

  cout << ans.size()/3 << endl;
  REP(i,ans.size()){
    cout << ans[i].fs+1 SP ans[i].sc+1 << " ";
    if(i%3==2) cout << endl;
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