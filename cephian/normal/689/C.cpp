#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll ways(ll n) {
  ll ans = 0;
  for(ll k = pow(n,1/3.0)+1; k > 1; --k) {
    ans += n/(k*k*k);
  }
  return ans;
}


int main() {
  ll m;
  cin >> m;
  ll lo = 1;
  ll hi = 5000000000000000LL;
  while(lo < hi-1) {
    ll mid = (lo+hi)/2;
    ll w = ways(mid);
    if(w < m) lo = mid;
    else hi = mid;
  }
  if(ways(hi) == m) cout << hi << "\n";
  else cout << "-1\n";
  return 0;
}