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
//#define int long long
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

vector<int> divisor(const int n){
  vector<int> ret;
  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      ret.push_back(i);
      if(i*i!= n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
}

const int mx = 2750132;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  vec flag(mx,0), prime;
  prime.emplace_back(-1);
  FOR(i,2,mx){
    if(flag[i]) continue;
    prime.push_back(i);
    FOR(j,2,mx){
      if(i*j >= mx) break;
      flag[i*j]++;
    }
  }

  flag.clear();

  map<int,int> mp;
  REP(_,2*n){
    int x;
    cin >> x;
    mp[x]++;
  }

  vec tmp,ans;
  RITR(itr,mp){
    if(itr->fs == *lower_bound(prime.begin(),prime.end(),itr->fs)) continue;
    //debug(itr->fs);
    tmp = divisor(itr->fs);
    REP(_,itr->sc) ans.emplace_back(itr->fs), mp[tmp[tmp.size()-2]]--;
    itr->sc = 0;
    
    tmp.clear();
  }

  ITR(itr,mp){
    while(itr->sc){
      //debug(itr->sc);
      ans.emplace_back(itr->fs);
      itr->sc--; mp[prime[itr->fs]]--;
    }
  }

  REP(i,n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}