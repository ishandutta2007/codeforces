#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int bits(int x) {
  if (x == 0) {
    return 0;
  } else {
    x -= x & (-x);
    return 1 + bits(x);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  ll s = 0;
  cin >> n;
  for (int m = 0; m <= (1 << n) - 1 - m; m++) {
    if (bits(m) == n / 2) {
      s++;
    }
  }
  for (int i = 1; i < n / 2; i++) {
    s *= i;
    s *= i;
  }
  cout << s << "\n";
}