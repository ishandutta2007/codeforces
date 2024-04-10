#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

bool debug = false;
int INF = 1e9;

int sx, sy, ex, ey;
int queries = 0;

void init() {
  queries = 0;
  if (debug) {
    sx = rand() % (INF - 2) + 2;
    sy = rand() % (INF - 2) + 2;
    ex = rand() % (INF - 2) + 2;
    ey = rand() % (INF - 2) + 2;
    if (sx > ex) {
      swap(sx, ex);
    }
    if (sy > ey) {
      swap(sy, ey);
    }
  }
}

int ask(int x, int y) {
  x = min(x, INF);
  y = min(y, INF);
  queries++;
  assert(queries <= 40);
  if (debug) {
    assert(!(sx <= x && x <= ex) || !(sy <= y && y <= ey));
    assert(x <= INF && y <= INF);
    if (sx <= x && x <= ex) {
      return min(abs(y - sy), abs(y - ey));
    } else if (sy <= y && y <= ey) {
      return min(abs(x - sx), abs(x - ex));
    } else {
      return min(abs(x - sx), abs(x - ex)) + min(abs(y - sy), abs(y - ey));
    }
  } else {
    cout << "? " << x << " " << y << endl;
    int ans;
    cin >> ans;
    assert(ans != -1);
    return ans;
  }
}

void check(int x1, int y1, int x2, int y2) {
  if (debug) {
    cout << queries << endl;
    assert(x1 == sx && x2 == ex && y1 == sy && y2 == ey);
  } else {
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    exit(0);
  }
}

void solve() {
  init();
  int x = 1, y = 1;
  int cur = ask(x, y);
  while (cur > 1) {
    int mv = (cur + 1) / 2;
    int z = ask(x + mv, y);
    if (z == cur - mv) {
      x += mv;
    } else {
      y += mv;
    }
    cur -= mv;
  }
  if (x == 1) {
    x++;
  } else if (y == 1) {
    y++;
  } else {
    int a = ask(x - 1, y + 1);
    if (a == 1) {
      y++;
    } else {
      x++;
    }
  }
  int distX = ask(INF, y);
  int x1 = INF - distX;
  int distY = ask(x, INF);
  int y1 = INF - distY;
  check(x, y, x1, y1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    solve();
  }
  return 0;
}