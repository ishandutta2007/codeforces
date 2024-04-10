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

int inversion(vector<int> &A, const int l, const int r, vector<int> &T) {
  if(r <= l+1) return 0;
  int cnt = 0;
  const int m = (l+r)/2;
  cnt += inversion(A,l,m,T) + inversion(A,m,r,T);

  int i = l, j = m, k = 0, c = 0;
  while(i < m && j < r){
    if(A[j] < A[i]) { //  A[j] <= A[i] 
      T[k++] = A[j++];
      c++;
    }
    else{
      T[k++] = A[i++];
      cnt += c;
    }
  }

  while(i < m){
    T[k++] = A[i++];
      cnt += c;
  }

  while(j < r) T[k++] = A[j++];

  for(int t = l; t < r; ++t) A[t] = T[t-l];

  return cnt;
}

int inversion(vector<int> &A, const int l, const int r) {
  vector<int> T(A.size(),0);
  return inversion(A,l,r,T);
}

void solve(){
  int N;
  string S;
  cin >> N >> S;

  vec a[26];
  REP(i,N) a[S[i]-'a'].push_back(i);
  REP(i,26) reverse(a[i].begin(),a[i].end());

  vec b(N);
  reverse(S.begin(),S.end());
  REP(i,N) b[i] = a[S[i]-'a'].back(), a[S[i]-'a'].pop_back();

  cout << inversion(b,0,N) << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}