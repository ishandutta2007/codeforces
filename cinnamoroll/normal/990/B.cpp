#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;
  
  map <int,int>v;
  
  REP(i,n){
      int a;
      cin >> a;
      v[a]++;
  }
  
  int ans = 0,size = MOD;
  for(auto itr = v.rbegin(); itr != v.rend(); ++itr){
      if(size - itr->first > k) ans += itr->second;
      size = itr->first;
  }
  
  cout << ans << endl;

  return 0;
}