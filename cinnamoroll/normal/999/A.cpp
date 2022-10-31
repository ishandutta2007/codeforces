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
  
  vector<int> q(n);
  
  REP(i,n){
      cin >>q[i];
  }
  
  int ans = 0,x = 0,xx = n-1;
  while(q[x] <= k){
      ans++;
      x++;
  }
  
  while(q[xx] <= k){
      ans++;
      xx--;
  }
  
  cout << min(ans,n) << endl;

  return 0;
}