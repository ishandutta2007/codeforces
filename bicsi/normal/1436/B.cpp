#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
  for (int d = 2; d * d <= x; ++d)
    if (x % d == 0)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int value;
    while (true) {
      value = rand() % 100000 + n;
      if (!is_prime(value) || is_prime(value - n + 1))
        continue;
      break;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (i == j) cout << value - n + 1 << " ";
        else cout << 1 << " ";
      cout << '\n';
    }
  }

  return 0;
}