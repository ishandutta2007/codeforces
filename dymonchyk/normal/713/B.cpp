#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct rect {
  int x1, y1, x2, y2;
};

void out(const rect &a) {
  cout << " " << a.x1 << " " << a.y1 << " " << a.x2 << " " << a.y2;
}

int n;

rect find(int x1, int x2, int y1, int y2) {
  { // x1
    int l = x1, r = x2 + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      cout << "? " << m << " " << y1 << " " << x2 << " " << y2 << endl;
      int cnt; cin >> cnt;
      if (cnt >= 1) l = m;
      else r = m;
    }
    x1 = l;
  }
  { // x2
    int l = x1 - 1, r = x2;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      cout << "? " << x1 << " " << y1 << " " << m << " " << y2 << endl;
      int cnt; cin >> cnt;
      if (cnt >= 1) r = m;
      else l = m;
    }
    x2 = r;
  }

  { // y1
    int l = y1, r = y2 + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      cout << "? " << x1 << " " << m << " " << x2 << " " << y2 << endl;
      int cnt; cin >> cnt;
      if (cnt >= 1) l = m;
      else r = m;
    }
    y1 = l;
  }
  { // y2
    int l = y1 - 1, r = y2;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      cout << "? " << x1 << " " << y1 << " " << x2 << " " << m << endl;
      int cnt; cin >> cnt;
      if (cnt >= 1) r = m;
      else l = m;
    }
    y2 = r;
  }
  return rect{x1, y1, x2, y2};
}

int get(int x1, int x2, int y1, int y2) {
  cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  int x; cin >> x;
  return x;
}

void solveX() {
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    cout << "? " << 1 << " " << 1 << " " << m << " " << n << endl;
    int cnt; cin >> cnt;
    if (cnt >= 1) r = m;
    else l = m;
  }

  if (get(1, r, 1, n) != 1 || get(r + 1, n, 1, n) != 1) return;

  rect r1 = find(1, r, 1, n), r2 = find(r + 1, n, 1, n);
  cout << "!";
  out(r1); out(r2);
  cout << endl;

  exit(0);
}

void solveY() {
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    cout << "? " << 1 << " " << 1 << " " << n << " " << m << endl;
    int cnt; cin >> cnt;
    if (cnt >= 1) r = m;
    else l = m;
  }

  if (r == n) return;

  rect r1 = find(1, n, 1, r), r2 = find(1, n, r + 1, n);
  cout << "!";
  out(r1); out(r2);
  cout << endl;

  exit(0);
}

int main() {
  cin >> n;
  solveX();
  solveY();

  return 0;
}