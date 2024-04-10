#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

int a[10][10], y;

mt19937 rng((long long) (new char));

void put(int n) {
  int r = 1, c = 1;
  while (n > 8) {
    int last;
    n -= 8;
    a[r][c] = ++y;
    for (int j = 8; j >= 1; j--) {
      if (j != c) {
        a[r][j] = ++y;
        last = j;
      }
    }
    r++;
    c = last;
  }
  if (n == 1) {
    r = 8;
  }
  n--;
  n--;
  if (r == 8) {
    n++;
  }
  a[r][c] = ++y;
  for (int j = 1; j <= 8; j++) {
    if (n >= 1 && j != c) {
      a[r][j] = ++y;
      n--;
    }
  }
  a[r][8] = ++y;
  if (r != 8) {
    a[8][8] = ++y;
  }
}

signed realMain() {
  int n, r = 1, c = 1, place;
  cin >> n;
  put(n);

  for (int x = 1; x <= n + 1; x++) {
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        if (a[i][j] == x) {
          cout << (char) ('a' + j - 1) << (char) ('1' + i - 1) << " ";
        }
      }
    }
  }
  cout << "\n";
  if (!home) {
    return 0;
  }
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (a[i][j] < 10) {
        cout << a[i][j] << "  ";
      } else {
        cout << a[i][j] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}