#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, p, l, a, d; cin >> n >> p >> l >> a >> d;
  
  // cerr << "p: " << p << " l: " << l << " a: " << a << endl;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }


  auto lc = [&](int i) -> long long { 
    return min(1LL * (v[i] + 1) * p, 1LL * l);
  };

  vector<long long> suff(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      suff[i] = min(1LL * v[i] * p + a, 1LL * 
        lc(i) + p + 2 * d);
    } else {
      suff[i] = min(1LL * v[i] * p + a, 1LL * 
        lc(i) + p); 
      suff[i] += suff[i + 1];
    }
  }


  // for (int i = 0; i < n; ++i) cerr << suff[i] << " "; cerr << endl;

  vector<long long> prefs(n, 0LL);

  long long pref = 0;
  long long best = 4e18;
  for (int i = 0; i < n; ++i) {
    prefs[i] = pref;
    // Laser.
    if (i + 1 < n) {
      assert(n - i - 1 >= 1);
      // cerr << "last is 1? " << n - i - 1 << endl;
      long long las = pref + 
        lc(i) + p + 2LL * d * (n - i - 1);
      las += suff[i + 1];
      // cerr << "LASER " << i << ": " << las << endl;
      best = min(best, las);
    }
    // No laser.
    long long now = pref + min(1LL * v[i] * p + a, 1LL * lc(i) + p + 2 * d);
    if (i >= 1) {
      long long now2 = prefs[i - 1] + lc(i - 1) + d + lc(i) + d + d + 2 * p;
      // cerr << "NOW2: " << i << ": " << now2 << endl;
      now = min(now, now2);
    }

    // cerr << "PREF " << i << ": " << now << endl;
    pref = now;
    if (i + 1 == n) {
      // cerr << "NO LASER: " << pref << endl;
      best = min(best, pref);
    }
    pref += d;
  }
  cout << best << endl;

  return 0;
}