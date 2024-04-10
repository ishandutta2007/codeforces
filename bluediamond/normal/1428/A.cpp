#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    if (dx == 0 || dy == 0) {
      cout << dx + dy << "\n";
    } else {
      cout << dx + dy + 2 << "\n";
    }
  }
}