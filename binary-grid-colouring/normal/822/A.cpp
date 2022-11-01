#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

int main(int argc, char const *argv[]) {
  int a,b;
  std::cin >> a >> b;
  ll ans = 1;
  for(int i=1;i<=min(a,b);i++) {
    ans *= i;
  }
  std::cout << ans << '\n';
  return 0;
}