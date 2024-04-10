#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;


std::map<int, int> mp;

int main(int argc, char const *argv[]) {

  int n,x;
  std::cin >> n  >> x;
  if(x==1) {
    std::cout << "1" << '\n';return 0;
  }
  ll ans = 0;
  for(int i = 1;i<=n;i++) {
    if(x % i == 0 && x / i <= n) {
      ans ++;
    }
  }
  std::cout << ans << '\n';
  return 0;
}