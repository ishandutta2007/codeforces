//  Copyright 2021 Nikita Golikov

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

  int n;
  double p;
  cin >> n >> p;
  int p4 = int(round(p * 10000));

  auto c3 = [](ll x) {
    return (x * (x - 1) * (x - 2)) / 6;
  };
  auto c2 = [](ll x) {
    return x * (x - 1) / 2;
  };

  for (int k = 0; k <= n; ++k) {
    ll num = 2 * c3(k) + 2 * c2(k) * (n - k) + k * c2(n - k);
    ll denom = 2 * c3(n);
    if (num * 10000 >= p4 * denom) {
      cout << k << '\n';
      return 0;
    }
  } 
  assert(false);  

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}