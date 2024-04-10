#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

ll solve(int n, int k, vector<ll> a, vector<ll> d) {
  ll res = 0;
  if (k == 0) {
    vector<ll> suff(n);
    for (int i = n - 1; i >= 0; i--) {
      suff[i] = a[i] + (i == n - 1 ? 0 : suff[i + 1]);
    }
    for (int i = 0; i < n; i++) {
      res = max(res, suff[i] - d[i]);
    }
  } else if (k == 1) {
    vector<ll> prefMin(n);
    vector<ll> prefSum(n);
    vector<ll> suffSum(n);
    vector<ll> startSuff(n);
    for (int i = 0; i < n; i++) {
      prefMin[i] = d[i];
      prefSum[i] = a[i];
      if (i > 0) {
        prefMin[i] = min(prefMin[i], prefMin[i - 1]);
        prefSum[i] += prefSum[i - 1];
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      suffSum[i] = a[i] + (i == n - 1 ? 0 : suffSum[i + 1]);
      startSuff[i] = suffSum[i] - d[i];
    }
    vector<ll> prefMaxStartSuff(n);
    vector<ll> suffMaxStartSuff(n);
    for (int i = n - 1; i >= 0; i--) {
      suffMaxStartSuff[i] = startSuff[i];
      if (i != n - 1) {
        suffMaxStartSuff[i] = max(suffMaxStartSuff[i], suffMaxStartSuff[i + 1]);
      }
    }
    for (int i = 0; i < n; i++) {
      prefMaxStartSuff[i] = startSuff[i];
      if (i > 0) {
        prefMaxStartSuff[i] = max(prefMaxStartSuff[i], prefMaxStartSuff[i - 1]);
      }
    }
    for (int i = 1; i + 1 < n; i++) {
      res = max(res, prefSum[i] - prefMin[i] + max(0LL, suffMaxStartSuff[i + 1]));
    }
    for (int i = 0; i + 2 < n; i++) {
      res = max(res, prefMaxStartSuff[i] - a[i + 1] + max(0LL, a[i + 1] - d[i + 1]));
    }
    res = max(res, suffMaxStartSuff[1]);
  } else {
    res = max(res, accumulate(a.begin(), a.end(), 0LL) - *min_element(d.begin(), d.end() - 1));
    res = max(res, a[n - 1] - d[n - 1]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<ll> a(n), d(n);
  for (ll &x : a) {
    cin >> x;
  }
  for (ll &x : d) {
    cin >> x;
  }
  cout << solve(n, min(2, k), a, d);
  return 0;
}