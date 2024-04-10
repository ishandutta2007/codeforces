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
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n;
    cin >> n;

    map<int,int> mp,mp2;
    REP(i,n){
      int x,y;
      cin >> x >> y;
      mp[x]++;
      if(y) mp2[x]++;
    }
    
    vector<P> a;
    ITR(itr,mp) a.emplace_back(P(itr->sc,mp2[itr->fs]));

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int ans = 0, ans2 = 0, cur = a[0].fs, id = 0;
    priority_queue<int> que;
    while(cur){
      while(id < a.size() && a[id].fs >= cur) que.push(a[id].sc), id++;
      if(que.size()){
        ans += cur;
        ans2 += min(cur,que.top()); que.pop();
      }
      cur--;
    }
    cout << ans SP ans2 << endl;
  }

  return 0;
}