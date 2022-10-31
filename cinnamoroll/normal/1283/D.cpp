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
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  set<int> st;
  vector<int> a(n);
  REP(i,n) cin >> a[i], st.insert(a[i]);
  
  sort(a.begin(),a.end());
  
  vec nx,pre;
  REP(i,n){
    if(st.find(a[i]+1)==st.end()) nx.push_back(a[i]+1);
    if(st.find(a[i]-1)==st.end()) pre.push_back(a[i]-1);
  }

  int sum = 0;
  vec ans;
  for(int i = 1;m;i++){
    for(int x:nx){
      if(m && st.find(x)==st.end()){
        sum += i; m--;
        st.insert(x);
        ans.push_back(x);
      }
    }
    for(int x:pre){
      if(m && st.find(x)==st.end()){
        sum += i; m--;
        st.insert(x);
        ans.push_back(x);
      }
    }
    vec tmp1, tmp2;
    for(int x:nx) if(st.find(x+1)==st.end()) tmp1.push_back(x+1);
    for(int x:pre) if(st.find(x-1)==st.end()) tmp2.push_back(x-1);
    nx = tmp1; pre = tmp2;
  }

  cout << sum << endl;
  REP(i,ans.size()) cout << ans[i] << " ";
  cout << endl;

  return 0;
}