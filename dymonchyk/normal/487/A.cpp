#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int hm, am, dm;

bool win(int hy, int ay, int dy) {
  if (ay <= dm) return false;
  if (am <= dy) return true;
  int r1 = (hm + max(0, ay - dm) - 1) / max(0, ay - dm);
  int r2 = (hy + max(0, am - dy) - 1) / max(0, am - dy);
  return (r1 < r2);
}

int main() {
  int hy, ay, dy, h, a, d;
  cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
  int ans = 1000000000;
  for (int H = 0; H <= 10000; ++H) {
    if (H * h >= ans) continue;
    for (int A = 0; A <= 200; ++A) {
      if (H * h + A * a >= ans) continue;
      for (int D = 0; D <= 100; ++D) {
        if (H * h + A * a + D * d >= ans) continue;
        if (win(hy + H, ay + A, dy + D))
          ans = H * h + A * a + D * d;
      } 
    }
  }
  cout << ans << endl;
  return 0;
}