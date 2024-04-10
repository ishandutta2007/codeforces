#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int n, p[200005];

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    p[t] = i;
  }
  ll ans = 0;
  for(int i = 1; i < n; ++i)
    ans += abs(p[i] - p[i+1]);
  cout << ans << "\n";
  return 0;
}