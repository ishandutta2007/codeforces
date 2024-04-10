#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll s, x, a;
  cin >> s >> x;
  if (s < x || s % 2 != x % 2) {
    cout << "0\n";
    return 0;
  }
  a = (s - x) / 2;
  ll sol = 1;
  for (ll bit = 0; bit <= 60; bit++) {
    ll in_xor = (x & (1LL << bit)) > 0;
    ll in_and = (a & (1LL << bit)) > 0;
    if (in_xor == 1 && in_and == 0) {
      sol *= 2;
    }
    if (in_xor == 1 && in_and == 1) {
      cout << "0\n";
      return 0;
    }
  }
  if (a == 0) {
    sol -= 2;
  }
  cout << sol << "\n";
}