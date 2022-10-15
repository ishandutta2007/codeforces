#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
ll a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  int l = 1, r = n;
  ll mn = 0, mx = (ll) 1e18;
  while (l < r) {
    ll sum;
    cin >> sum;
    /// x, sum - x
    /// mn <= x
    /// sum - x <= mx
    /// mn <= x
    /// sum - mx <= x
    ll x = max(mn, sum - mx);
    ll y = sum - x;
    a[l] = x;
    a[r] = y;
    l++;
    r--;
    mn = x;
    mx = y;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}