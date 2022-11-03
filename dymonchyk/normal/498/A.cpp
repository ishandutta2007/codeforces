#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int sgn(long long x) {
  return (x > 0) - (x < 0);
}

int main() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int ans = 0, a, b, c, n;
  cin >> n;
  while (cin >> a >> b >> c) {
    ans += sgn(a * x1 + b * y1 + c) != sgn(a * x2 + b * y2 + c);
  }
  cout << ans << endl;
  return 0;
}