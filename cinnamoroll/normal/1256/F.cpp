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
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
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
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

//1e6
//a[i]>a[j]  i<j
const int NMAX = 1e6+10;
vector<int> T;
int inversion(string &A, const int l, const int r) {
  if(r <= l+1) return 0;
  int cnt = 0;
  const int m = (l+r)/2;
  cnt += inversion(A,l,m) + inversion(A,m,r);

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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n;
    string s,t;
    cin >> n >> s >> t;

    T.assign(n,0);
    int x = inversion(s,0,n);
    T.assign(n,0);
    int y = inversion(t,0,n);
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    bool flag = x%2==y%2;
    REP(i,n-1) if(s[i]==s[i+1] || t[i]==t[i+1]) flag = true;
    if(flag && s==t) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }

  return 0;
}