#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;
char s[500005];

void add(int &r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int main() {
  int n, h, w;
  scanf("%d%d%d\n%s\n", &n, &h, &w, s);

  int minx = 0, maxx = 0, miny = 0, maxy = 0, curx = 0, cury = 0, ans = 0;

  const int K = 3;
  int ind = 0, it = 0;
  while (it < K * n) {
    ++it;
    if (maxx - minx == w || maxy - miny == h) break;
  
    switch (s[ind]) {
      case 'R':
        ++curx;
        break;
      case 'L':
        --curx;
        break;
      case 'U':
        ++cury;
        break;
      case 'D':
        --cury;
        break;
    }
    ind = (ind + 1) % n;

    if (curx > maxx) {
      add(ans, 1LL * it * (h - (maxy - miny)) % mod);
      maxx = curx;
    }
    if (curx < minx) {
      add(ans, 1LL * it * (h - (maxy - miny)) % mod);
      minx = curx;
    }

    if (cury > maxy) {
      add(ans, 1LL * it * (w - (maxx - minx)) % mod);
      maxy = cury;
    }
    if (cury < miny) {
      add(ans, 1LL * it * (w - (maxx - minx)) % mod);
      miny = cury;
    }
  }

  // cout << ind << endl;
  vector<pair<int, int>> ev;
  while (it < (K + 1) * n) {
    ++it;
    if (maxx - minx == w || maxy - miny == h) break;
  
    switch (s[ind]) {
      case 'R':
        ++curx;
        break;
      case 'L':
        --curx;
        break;
      case 'U':
        ++cury;
        break;
      case 'D':
        --cury;
        break;
    }
    ind = (ind + 1) % n;

    if (curx > maxx) {
      add(ans, 1LL * it * (h - (maxy - miny)) % mod);
      maxx = curx;
      ev.push_back({1, it - K * n});
    }
    if (curx < minx) {
      add(ans, 1LL * it * (h - (maxy - miny)) % mod);
      minx = curx;
      ev.push_back({2, it - K * n});
    }

    if (cury > maxy) {
      add(ans, 1LL * it * (w - (maxx - minx)) % mod);
      maxy = cury;
      ev.push_back({3, it - K * n});
    }
    if (cury < miny) {
      add(ans, 1LL * it * (w - (maxx - minx)) % mod);
      miny = cury;
      ev.push_back({4, it - K * n});
    }
  }

  if (ev.size()) {
    for ( ; ; ) {
      if (maxx - minx == w || maxy - miny == h) break;
      for (auto p : ev) {
        if (maxx - minx == w || maxy - miny == h) break;
        
        if (p.first == 1) {
          add(ans, 1LL * (it + p.second) * (h - (maxy - miny)) % mod);
          maxx++;
        }
        if (p.first == 2) {
          add(ans, 1LL * (it + p.second) * (h - (maxy - miny)) % mod);
          minx--;
        }

        if (p.first == 3) {
          add(ans, 1LL * (it + p.second) * (w - (maxx - minx)) % mod);
          maxy++;
        }
        if (p.first == 4) {
          add(ans, 1LL * (it + p.second) * (w - (maxx - minx)) % mod);
          miny--;
        }
      }
      add(it, n);
    }
  }

  if (maxx - minx < w && maxy - miny < h) ans = -1;

  printf("%d\n", ans);
  return 0;
}