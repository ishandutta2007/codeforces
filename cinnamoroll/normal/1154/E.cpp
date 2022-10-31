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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  vec a(n);
  map<int,int> mp;
  REP(i,n) cin >> a[i], mp[a[i]] = i;

  vec ans(n,-1),L(n,-1),R(n,-1);
  REP(i,n-1) L[i] = i+1;
  REP(i,n-1) R[i+1] = i;

  set<int> st;
  REP(i,n) st.insert(i+1);

  int cur = 1;
  while(st.size()){
    int tmp = *st.rbegin(), id = mp[tmp], id2 = mp[tmp];
    ans[id] = cur;
    st.erase(tmp);
    
    REP(_,k){
      id = L[id];
      if(id == -1) break;
      ans[id] = cur;
      st.erase(a[id]);
    }

    REP(_,k){
      id2 = R[id2];
      if(id2 == -1) break;
      ans[id2] = cur;
      st.erase(a[id2]);
    }

      int left = -1;
      if(id != -1) left = L[id];
      int right = -1;
      if(id2 != -1) right = R[id2];
      if(right != -1) L[right] = left;
      if(left != -1) R[left] = right;
      //debug(left);debug(right);
    

    //REP(i,n) cout << L[i] SP R[i] << endl;

    cur ^= 1;
  }

  REP(i,n){
    if(ans[i]) cout << 1;
    else cout << 2;
  }

  return 0;
}