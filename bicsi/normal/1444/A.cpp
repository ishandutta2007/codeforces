#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

long long Solve(long long p, int q) {
  int _q = q;
  vector<pair<int, int>> facts;
  if (p % q) return p;
  for (int d = 2; d * d <= q; ++d) {
    int e = 0;
    while (q % d == 0) {
      ++e;
      q /= d;
    }
    if (e) 
      facts.emplace_back(d, e);
  }
  if (q > 1) facts.emplace_back(q, 1);

  long long best = 1;
  // for (auto [d, e] : facts) {
  //   cerr << d << " " << e << endl;
  // }
  for (auto [d, e] : facts) {
    long long pp = p;
    while (pp % d == 0) pp /= d;
    for (int i = 1; i < e; ++i)
      pp *= d;
    // cerr << p << " " << pp << " " << _q << endl;
    assert(p % pp == 0);
    assert(pp % _q != 0);
    best = max(best, pp);
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // while (true) {
  //   int p = rand() % 100000 + 100;
  //   int q = rand() % 100 + 100;
  //   Solve(p, q);
  //   cerr << "OK" << endl;
  // }

  int t; cin >> t;
  while (t--) {
    long long p; int q; cin >> p >> q;
    cout << Solve(p, q) << '\n';
  }

  return 0;
}