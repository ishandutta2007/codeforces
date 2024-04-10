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
typedef vector<int> vec;
typedef vector<vector<int>> mat;


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<P> a,b;
  REP(_,m){
    int k,x,y;
    cin >> k >> x >> y;
    if(k){
      a.emplace_back(P(x,y));
    }
    else{
      b.emplace_back(P(x,y));
    }
  }

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  if(a.size() == 0){
    cout << "YES" << endl;
    REP(i,n) cout << n-i << " ";
    cout << endl;
    return 0;
  }

  if(b.size() == 0){
    cout << "YES" << endl;
    REP(i,n) cout << i+1 << " ";
    cout << endl;
    return 0;
  }

vector<P> c,d;
  int now = 1,mn = INF;
  vec ans(n+1,INF);
  int l = a[0].fs, r = a[0].sc;
  REP(i,a.size()){
    if(i != a.size()-1 && a[i+1].fs <= r){
      r = max(r,a[i+1].sc);
      continue;
    }
    c.emplace_back(P(l,r));
    if(i != a.size()-1) l = a[i+1].fs, r = a[i+1].sc;
  }

  l = b[0].fs; r = b[0].sc;
  REP(i,b.size()){
    if(i != b.size()-1 && b[i+1].fs <= r){
      r = max(r,b[i+1].sc);
      continue;
    }
    d.emplace_back(P(l,r));
    if(i != b.size()-1) l = b[i+1].fs, r = b[i+1].sc;
  }

  int id = 1;
  REP(i,c.size()){
    //cout << c[i].fs SP c[i].sc << endl;
    FOR(j,id,c[i].fs) ans[j] = now, now--;
    FOR(j,c[i].fs,c[i].sc+1) ans[j] = now, now++;
    now -= 2;
    id = c[i].sc+1;
  }

  FOR(i,id,n+1) ans[i] = now, now--;

  //FOR(i,1,n+1) cout << ans[i] << " ";
  //cout << endl;

  REP(i,b.size()){
    //cout << b[i].fs SP b[i].sc << endl;
    bool f = true;
    FOR(j,b[i].fs,b[i].sc){
      
      //cout << ans[j] SP ans[j+1] << endl;
      if(ans[j] > ans[j+1]) f = false;
      

    }      if(f){
        cout << "NO" << endl;
        return 0;
      }
  }

  cout << "YES" << endl;
  FOR(i,1,n+1) mn = min(ans[i],mn);

  FOR(i,1,n+1) cout << ans[i]-(mn-1) << " ";
  cout << endl;

  return 0;
}