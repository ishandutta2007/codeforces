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
#define pcnt(x) (__builtin_popcount(x))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
vector<int> pri;
void init(int x){
  vector<bool> flag(x+1,false);
  for(int i = 2; i <= x; i++){
    if(flag[i]) continue;
    pri.emplace_back(i);
    for(int j = i; j <= x; j+=i) flag[j] = true;
  }
}
 
int n,k;
map<long long,int> Primefactorization(long long x){
  map<long long, int> mp;
  for(int p:pri){
    int cnt = 0;
    if(p>x) break;
    while(x%p==0) x /= p, cnt++;
    if(cnt%k) mp[p] = cnt%k;
  }
  if(x != 1) mp[x] = 1;
  return mp;
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  
  cin >> n >> k;
 
  init(100010);
 
  vector<int> a(100010,0);
  int ans = 0;
  map<map<int,int>,int> mp;
  REP(i,n){
    int x; cin >> x;
    map<int,int> m = Primefactorization(x), m2;
 
    ITR(itr,m) m2[itr->fs] = k-itr->sc;
    ans += mp[m];
    mp[m2]++;
  }
 
  cout << ans << endl;
 
  return 0;
}