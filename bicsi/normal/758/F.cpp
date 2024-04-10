#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, l, r; cin >> n >> l >> r;
  
  if (n >= 30) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1) {
    cout << r - l + 1 << endl;
    return 0;
  }

  if (n == 2) {
    int len = r - l + 1;
    long long ans = 1LL * len * len - len;
    cout << ans << endl;
    return 0;
  }

  vector<int> small(r + 1, 1);
  for (int i = 2; i <= r; ++i) {
    if (small[i] == 1) {
      // i is prime
      for (int j = i; j <= r; j += i) {
        if (small[j] == 1)
          small[j] = i;
      }
    }
  }

  vector<int> mem(r + 10, -1);
  auto pw = [&](int x) {
    if (mem[x] != -1) return mem[x];
    long long res = 1;
    for (int i = 0; i < n - 1; ++i) {
      res *= x;
      if (res > 1e9) break;
    }
    return mem[x] = min((int)res, (int)1e9);
  };

  int ans = 0;
  // Assume ratio is > 1
  for (int a = l; a <= r; ++a) {
    // highest y such that y ^ {n - 1} divides a
    int y = 1;
    int aux = a;
    while (aux > 1) {
      int p = small[aux];
      int e = 0;
      while (aux % p == 0) {
        aux /= p;
        e += 1;
      }

      e /= n - 1;
      for (int i = 0; i < e; ++i) {
        y *= p;
      }
    }
    
    // Compute the highest x such that a * x^{n - 1} / y^{n - 1} <= r
    assert(a % pw(y) == 0);
    int ap = a / pw(y);

    // cerr << "ap: " << ap << endl;
    
    for (int x = y + 1; 1LL * pw(x) * ap <= r; ++x) {
      // cerr << "GOOD: " << a << " with ratio: " << x << "/" << y << endl;
      ans += 1;
    }
  }
  cout << ans * 2 << endl;

  return 0;
}