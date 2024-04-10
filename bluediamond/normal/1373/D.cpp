#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = (int) 2e5 + 7;
const ll OO = (ll) 1e18;
int n;
ll a[N];
ll odd[N];
ll even[N];
ll mx[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      odd[i] = odd[i - 1];
      even[i] = even[i - 1];
      if (i % 2 == 1) {
        odd[i] += a[i];
      } else {
        even[i] += a[i];
      }
    }
    mx[0] = mx[1] = -OO;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ll cur = mx[(i - 1) % 2];
      ans = max(ans, cur + even[i] - odd[i]);
      mx[i % 2] = max(mx[i % 2], odd[i - 1] - even[i - 1]);
    }
    cout << odd[n] + ans << "\n";
  }
  return 0;
}