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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
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

  int t;
  cin >> t;

  REP(_,t){
    int n,m;
    cin >> n >> m;

    vector<string> s(n);
    REP(i,n) cin >> s[i];
    
    vector<P> a[26];
    REP(i,n) REP(j,m){
      if(s[i][j] == '.') continue;
      a[s[i][j]-'a'].push_back(P(i,j));
    }

    mat flag(n,vec(m,0));
    vector<tuple<int,int,int,int>> ans;
    RREP(i,26){
      if(a[i].size() == 0 && ans.size() == 0) continue;
      if(a[i].size() != 0){
      bool check = true;
      int x = a[i][0].fs, y = a[i][0].sc+1;
      FOR(j,1,a[i].size()){
        if(a[i][j].fs != x){
          check = false;
          break;
        }
        while(y < m && flag[x][y]) y++;
        if(a[i][j].sc != y){
          check = false;
          break;
        }
        y++;
      }

      bool check2 = true;
      x = a[i][0].fs+1; y = a[i][0].sc;
      FOR(j,1,a[i].size()){
        if(a[i][j].sc != y){
          check2 = false;
          break;
        }
        while(x < n && flag[x][y]) x++;
        if(a[i][j].fs != x){
          check2 = false;
          break;
        }
        x++;
      }
      
      if(!check && !check2){
        cout << "NO" << endl;
        goto out;
      }
      }
      REP(j,a[i].size()) flag[a[i][j].fs][a[i][j].sc]++;
      to:;
      if(a[i].size() == 0) ans.push_back(ans.back());
      else ans.push_back(tie(a[i][0].fs,a[i][0].sc,a[i].back().fs,a[i].back().sc));
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    //debug(ans.size());
    RREP(i,(int)ans.size()){
      int a,b,c,d;
      tie(a,b,c,d) = ans[i];
      cout << a+1 SP b+1 SP c+1 SP d+1 << endl;
    }
    out:;
  }

  return 0;
}