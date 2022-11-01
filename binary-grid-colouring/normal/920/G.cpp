#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;

std::vector<int> divsior[1000010];

ll query(ll x,ll p)
{
  ll ans = 0;
  for(int i = 0;i < (1 << divsior[p].size());i++) {
    int cnt = 0;
    int v = 1;
    for(int j = 0;j < (int)divsior[p].size();j++) {
      if((1<<j) & i) {
        cnt++;
        v *= divsior[p][j];
      }
    }
    if(cnt&1) {
      ans -= (x / v);
    }
    else ans += (x / v);
  }
  // std::cout << "ans=" << ans << '\n';
  return ans;
}
// divsior[p][j] represent the j_th divsior of p is divsior[p][j]
int main(int argc, char const *argv[]) {
  int t;
  int x,p,k;
  for(int i=2;i<=1e6;i++) {
    if(divsior[i].empty()) {
      for(int j=i;j<=1e6;j+=i) {
        divsior[j].push_back(i);
      }
    }
  }
 // for(auto x: divsior[10]) {
 //   std::cout << "x=" << x << '\n';
 // }
  std::cin >> t;
  for(int i=1;i<=t;i++) {
    std::cin >> x >> p >> k;
    ll kk = query(x,p);
    ll low = x, high = 1e14;
    while(low<=high) {
      ll mid = (low + high) >> 1;
      if(query(mid,p) - kk >= k) {
        high = mid - 1;
      }
      else low = mid + 1;
    }
    std::cout << low << '\n';
  }

  return 0;
}