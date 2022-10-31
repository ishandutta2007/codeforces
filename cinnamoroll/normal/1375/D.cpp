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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n;
    cin >> n;

    vector<int> a(n),b(n+1,0);
    REP(i,n){
      cin >> a[i], b[a[i]]++;
    }

    int x = 0;
    while(b[x]) x++;

    vec ans;
    int id = 0;
    while(id<n && x < n){
      if(b[a[id]]==1 && a[id]!=n) id++;
      else{
        b[a[id]]--;
        a[id] = x;
        b[a[id]]++;
        ans.push_back(id+1);
        id++;
        while(b[x]) x++;
      }
    }

    REP(i,n){
      if(a[i]==i) continue;
      ans.push_back(i+1);
      int now = a[i]; a[i] = n;
      while(1){
        ans.push_back(now+1);
        swap(a[now],now);
        if(now==n) break;
      }
    }

    // REP(i,n) cout << a[i] << " ";
    // cout << endl;

    cout << ans.size() << endl;
    REP(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
  }

  return 0;
}