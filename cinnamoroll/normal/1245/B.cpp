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
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  map<char,int> mp;
  mp['S'] = 0; mp['R'] = 1; mp['P'] = 2;
  char c[] = {'R','P','S'};

  REP(_,q){
    int n;
    cin >> n;

    vector<int> a(3);
    REP(i,3) cin >> a[i];
    
    string s;
    cin >> s;

    vec ans(n,-1); int cnt = 0;
    REP(i,n){
      int id = mp[s[i]];
      if(a[id]){
        ans[i] = id;
        a[id]--;
        cnt++;
      }
    }

    if(n>cnt*2){
      cout << "No" << endl;
      continue;
    }
    
    cout << "Yes" << endl;

    int now = 0;
    REP(i,n){
      if(ans[i]!=-1) continue;
      while(a[now]==0) now++;
      ans[i] = now;
      a[now]--;
    }

    REP(i,n) cout << c[ans[i]];
    cout << endl;
  }

  return 0;
}