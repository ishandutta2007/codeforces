#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  int n;
  ll ans = 0;
  ll prev = 0;
  cin >> n;
  while(n--) {
    ll a;
    cin >> a;
    ans += abs(a - prev);
    prev = a;
  }
  cout << ans << "\n";
  return 0;
}