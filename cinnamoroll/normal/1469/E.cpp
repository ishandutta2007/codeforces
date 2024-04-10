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
 
//2^128(U32) xor shift
unsigned long xor128() {
  static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
  unsigned long t=(x^(x<<11));
  x=y; y=z; z=w;
  return ( w=(w^(w>>19))^(t^(t>>8)) );
}
 
void solve(){
  int N,K;
  string S;
  cin >> N >> K >> S;

  vec sum(N+1,0);
  REP(i,N){
    sum[i+1] += sum[i];
    sum[i+1] += '1'-S[i];
  }
 
  set<int> st;
  REP(i,N-K+1){
    if(sum[max(i,i+K-20)]-sum[i]) continue;
    int tmp = 0;
    FOR(j,max(i,i+K-20),i+K) tmp *= 2, tmp += S[j]-'0';
    tmp ^= ((1<<min(20LL,K))-1);
    st.insert(tmp);
    //debug(tmp);
  }
 
  int i = 0; 
  ITR(itr,st){
    if(i >= (1<<min(20LL,K))) break;
    if((*itr)==i){
      i++;
      //debug(i);
      continue;
    }
    cout << "YES" << endl;
    REP(_,max(0LL,K-20)) cout << 0;
    RREP(j,min(20LL,K)){
      if(parity(i,j)) cout << 1;
      else cout << 0;
    }
    cout << endl;
    return;
  }
 
  if(i < (1<<min(20LL,K))){
      cout << "YES" << endl;
    REP(_,max(0LL,K-20)) cout << 0;
    RREP(j,min(20LL,K)){
      if(parity(i,j)) cout << 1;
      else cout << 0;
    }
    cout << endl;
    return;
  }
 
  cout << "NO" << endl;
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T = 1;
  cin >> T;
 
  while(T--) solve();
 
  return 0;
}