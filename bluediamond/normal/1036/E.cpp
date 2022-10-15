#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
const int N = 1000 + 7;
int n, x1[N], y1[N], x2[N], y2[N], a[N], b[N], c[N];

bool onSegment(int xx, int yy, int ind) {
  int minX = min(x1[ind], x2[ind]);
  int maxX = max(x1[ind], x2[ind]);
  int minY = min(y1[ind], y2[ind]);
  int maxY = max(y1[ind], y2[ind]);

  return minX <= xx && xx <= maxX && minY <= yy && yy <= maxY;
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  int Solution = 0;

  for (int i = 1; i <= n; i++) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    a[i] = y2[i] - y1[i];
    b[i] = x1[i] - x2[i];
    c[i] = y1[i] * x2[i] - x1[i] * y2[i];

    int dx = x2[i] - x1[i];
    int dy = y2[i] - y1[i];

    dx = abs(dx);
    dy = abs(dy);

    Solution += __gcd(dx, dy) + 1;


    set<pair<int, int>> Points;

    for (int j = 1; j < i; j++) {
      int a1 = a[i], b1 = b[i], c1 = c[i];
      int a2 = a[j], b2 = b[j], c2 = c[j];

      int UP = c1 * a2 - a1 * c2, DOWN = b1 * a2 - a1 * b2;

      if (DOWN == 0) {
        continue;
      }

      assert(DOWN != 0);

      if (UP % DOWN) {
        continue;
      }

      int y = UP / DOWN;


      swap(a1, b1);
      swap(a2, b2);


      UP = c1 * a2 - a1 * c2, DOWN = b1 * a2 - a1 * b2;

      if (DOWN == 0) {
        continue;
      }

      assert(DOWN != 0);

      if (UP % DOWN) {
        continue;
      }

      int x = UP / DOWN;
      x *= -1;
      y *= -1;

      if (onSegment(x, y, i) && onSegment(x, y, j)) {
        Points.insert({x, y});
      }
    }

    Solution -= (int) Points.size();
  }

  cout << Solution << "\n";

  return 0;
}