#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void print(int n) {
  if (n == 4) {
    cout << "1 * 2 = 2\n";
    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
    return;
  }
  if (n == 5) {
    cout << "4 - 1 = 3\n";
    cout << "2 + 5 = 7\n";
    cout << "3 * 7 = 21\n";
    cout << "21 + 3 = 24\n";
    return;
  }
  print(n - 2);
  cout << n << " - " << (n - 1) << " = " << 1 << "\n";
  cout << "1 * 24 = 24\n";
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  if (n < 4) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  print(n);

  return 0;
}
/**
1, 2, 3, 4, 5
24 = 8 * 3
3 * ()

21 + 3

1, 2, 4, 5 formez pe 21

(4 - 1) * (2 + 5) + 3
**/