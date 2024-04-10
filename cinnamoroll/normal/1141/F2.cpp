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

  int n;
  cin >> n;

  vec a(n);
  REP(i,n) cin >> a[i];

  vec sum(n+1,0);
  REP(i,n) sum[i+1] = sum[i] + a[i];
  
  map<int,int> mp;
  int NMAX = 1500*1500;
  vector<P> tmp[NMAX];
  int num = 1;
  REP(i,n){
    FOR(j,i,n){
      int cur = sum[j+1]-sum[i];
      if(mp[cur] == 0) mp[cur] = num, num++;
      tmp[mp[cur]-1].push_back(P(j+1,i+1));
    }
  }

  vector<P> ans;
  REP(i,num-1){
    sort(tmp[i].begin(),tmp[i].end());
    int r = 0;
    vector<P> cur;
    REP(j,tmp[i].size()){
      if(r < tmp[i][j].sc){
        cur.push_back(tmp[i][j]);
        r = tmp[i][j].fs;
      }
    }
    if(ans.size() < cur.size()) ans = cur;
  }

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i].sc SP ans[i].fs << endl;

  return 0;
}