#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[1000 + 7];
int b[1000 + 7];
int c[1000 + 7];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 1000; i++) {
    a[i] = b[i] = c[i] = -1;
  }
  for (int x = 0; 3 * x <= 1000; x++) {
    for (int y = 0; 3 * x + 5 * y <= 1000; y++) {
      for (int z = 0; 3 * x + 5 * y + 7 * z <= 1000; z++) {
        a[3 * x + 5 * y + 7 * z] = x;
        b[3 * x + 5 * y + 7 * z] = y;
        c[3 * x + 5 * y + 7 * z] = z;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (a[n] == -1) {
      cout << "-1\n";
    } else {
      cout << a[n] << " " << b[n] << " " << c[n] << "\n";
    }
  }
}