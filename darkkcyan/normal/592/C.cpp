#include <bits/stdc++.h>
using namespace std;

#define llong long long 

bool isoutofrange(llong u, llong v) {
  return log2(u) + log2(v) > 63;
}

int main() {
  llong t, n, m; cin >> t >> n >> m;

  if (n > m) swap(n, m);
  llong nm = isoutofrange(n / __gcd(n, m), m) ? t + 1 : n / __gcd(n, m) * m;
  llong ans = t / nm * n - 1;
  llong md = t - t % nm;
  ans += min(t, md + n - 1) - md + 1;
  llong x = __gcd(ans, t);
  cout << ans / x << '/' << t / x;

  return 0;
}