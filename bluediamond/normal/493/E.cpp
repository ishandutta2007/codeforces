/// 484 -> 485
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll evaluate(vector<ll> poly, ll x) {
  ll sol = 0, cur = 1;
  for (auto &c : poly) {
    sol += cur * c;
    cur *= x;
  }
  return sol;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  ll t, a, b;
  cin >> t >> a >> b;
  if (t > 1) {
    /**
    p(t) = a
    p(a) = b

    we have a > coefficient(i) => the polynomial coefficients are the digits of b in base a

    **/

    ll sol = 0, copyB = b;
    if (a > 1) {
      vector<ll> coefs;

      while (copyB > 0) {
        coefs.push_back(copyB % a);
        copyB /= a;
      }

      assert(evaluate(coefs, a) == b);
      if (evaluate(coefs, t) == a) {
        sol++;
      }

    }
    sol += (a == b);
    cout << sol << "\n";

    return 0;
  }
  assert(t == 1);
  if (a == 1 && b == 1) {
    cout << "inf\n";
    return 0;
  }
  if (a == 1) {
   /// cout << "to be completed\n";
    cout << "0\n";
    exit(0);
  }
  ll value = b;
  while (value > a) {
    value /= a;
  }
  if (value == a) {
    cout << "1\n";
    return 0;
  }
  cout << "0\n";
}