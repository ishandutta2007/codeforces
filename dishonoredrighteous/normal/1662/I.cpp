//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int& x : p) {
    cin >> x;
  }
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + p[i];
  }

  vector<ll> pos(m);
  for (ll& x : pos) {
    cin >> x;
    x *= 2;
  }
  sort(pos.begin(), pos.end());
  ll ans = 0;

  auto GetR = [&](ll i) {
    return (i - i % 200) / 200;
  };

  auto Get = [&](ll l, ll r) -> ll {
    smin(r, n - 1);
    if (l > r) {
      return 0;
    }
    return pref[r + 1] - pref[l];
  };

  int j = 0;
  for (int i = 0; i < n; ++i) {
    ll coord = i * 100 * 2;
    while (j + 1 < m && pos[j + 1] <= coord) {
      ++j;
    }
    if (j < m && pos[j] == coord) {
      continue;
    }
    auto was = j < m && pos[j] <= coord;
    ll mx = (was ? 2 * coord - pos[j] : ll(3.1e9)) - 1;
    if (j + 1 < m) {
      smin(mx, pos[j + 1] - 1);
    }
    if (pos[j] > coord) {
      smin(mx, pos[j] - 1);
    }
    if ((j < m && pos[j] > coord) || j + 1 < m) {
      ll R = j < m && pos[j] > coord ? pos[j] : pos[j + 1];
      if (mx == R) {
        continue;
      }
      mx = (mx + R - 1) / 2;
    } else {
      mx = ll(3.1e9);
    }

    // cerr << i << ' ' << j << ' ' << mx << '\n';
    smax(ans, Get(i, GetR(mx)));
  }

  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}