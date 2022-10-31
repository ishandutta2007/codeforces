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

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  k = k*8/n;

  int lim = 1;
  while(k && lim < 1e6){
    lim *= 2;
    k--;
  }

  vector<int> a(n);
  map<int,int> mp;
  REP(i,n) cin >> a[i], mp[a[i]]++;
  
  auto r = compress(a);
  auto v = dict(r);

  int ans = 0, l = 0, cnt = 0;
  REP(i,v.size()){
    cnt += mp[r[i]];//debug(cnt);
    if(i >= lim) cnt -= mp[r[l]],l++;
    //debug(cnt);
    ans = max(ans,cnt);
  }

  cout << n-ans << endl;


  return 0;
}