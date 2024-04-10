#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k; cin >> n >> k; k -= n;
  vector<int> a(n);
  vector<int> parts(n, 1);

  auto calc = [&](int x, int c) {
    assert(c > 0);
    int mean = x / c;
    int rem = x % c;
    return 1LL * mean * mean * c + 1LL * rem * (2 * mean + 1);
  };
  auto delta = [&](int i) {
    long long now = calc(a[i], parts[i]);
    long long nxt = calc(a[i], parts[i] + 1);
    return now - nxt;
  };

  long long total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    total += 1LL * a[i] * a[i];
  }

  priority_queue<pair<long long, int>> pq;
  for (int i = 0; i < n; ++i)
    pq.emplace(delta(i), i);

  for (int it = 0; it < k; ++it) {
    // cerr << it << " " << total << endl;
    auto [win, i] = pq.top(); pq.pop();
    total -= win;
    ++parts[i];
    pq.emplace(delta(i), i);
  }

  cout << total << endl;


  return 0;
}