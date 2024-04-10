#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100 + 7;
int n, a[N];

signed main() {
  cin >> n;

  /// let's find the last element

  for (int x = 1; x < n; x++) {

    cout << "? ";
    for (int i = 1; i < n; i++) {
      cout << x + 1 << " ";
    }
    cout << 1 << endl;

    /// daca elementul este x => voi avea s(n) = x + 1 dar s(i) cu i < n va fi > x + 1

    /// daca elementul nu este x => voi avea s(n) = a + 1 cu a > x
    /// voi demonstra ca vom avea b + x + 1 = a + 1
    /// b + x = a
    /// => b = a - x care exista pentru ca a > x

    int r;
    cin >> r;
    if (r == 0) {
      a[n] = x;
      break;
    }
  }
  if (!a[n]) {
    a[n] = n;
  }

  for (int val = 1; val <= n; val++) {
    if (val == a[n]) {
      continue;
    }
    /// avem val + x = a[n] + y
    /// val - a[n]
    for (int x = 1; x <= n; x++) {
      int y = val + x - a[n];
      if (1 <= y && y <= n) {
        cout << "? ";
        for (int i = 1; i < n; i++) {
          cout << x << " ";
        }
        cout << y << endl;
        int r;
        cin >> r;
        a[r] = val;
        break;
      }
    }
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;


  return 0;
}