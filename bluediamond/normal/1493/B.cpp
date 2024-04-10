#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int h, m;

int inv(int x) {
  if (x == 0) return 0;
  if (x == 1) return 1;
  if (x == 2) return 5;
  if (x == 3) return -1;
  if (x == 4) return -1;
  if (x == 5) return 2;
  if (x == 6) return -1;
  if (x == 7) return -1;
  if (x == 8) return 8;
  if (x == 9) return -1;
  exit(0);
  assert(0);
}

int f(int x) {
  if (x <= 9) return inv(x) * 10;
  int c1 = x / 10, c2 = x % 10;
  if (c1 == 10) {
    cout << "loool : " << x << "\n";
  }
  if (inv(c1) == -1 || inv(c2) == -1) return -1;
  return inv(c2) * 10 + inv(c1);
}

bool valid(int a, int b) {
  a = f(a);
  b = f(b);
  if (a == -1 || b == -1) return 0;
  return (0 <= a && a < m && 0 <= b && b < h);
}

void p(int x) {
  if (x <= 9) cout << "0";
  cout << x;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> h >> m >> s;
    int a = 10 * (s[0] - '0') + (s[1] - '0');
    int b = 10 * (s[3] - '0') + (s[4] - '0');
    while (!valid(a, b)) {
      b++;
      if (b == m) {
        b = 0;
        a++;
        if (a == h) {
          a = 0;
        }
      }
    }
    p(a);
    cout << ":";
    p(b);
    cout << "\n";
  }
}