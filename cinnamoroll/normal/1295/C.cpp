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

//SijindexO(|S|*)
mat next_index(string &s){
  int len = s.size();
  mat nx(len,vec(26,INF));
  REP(i,len) nx[i][s[i]-'a'] = i+1;
  RREP(i,len-1) REP(j,26) nx[i][j] = min(nx[i][j],nx[i+1][j]);
  return nx;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    string s,t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    mat nx = next_index(s);

    int id = 0, ans = 0; bool flag = true;
    while(id<m&&flag){
      flag = false; ans++;
      int now = 0;
      while(now < n && id < m){
        now = nx[now][t[id]-'a'];
        if(now!=INF) id++, flag = true;
      }
    }
    if(!flag) cout << -1 << endl;
    else cout << ans << endl;
  }

  return 0;
}