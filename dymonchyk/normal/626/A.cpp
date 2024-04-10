#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int dx = 0, dy = 0;
      for (int t = i; t <= j; ++t) {
        if (s[t] == 'U') ++dy;
        if (s[t] == 'D') --dy;
        if (s[t] == 'L') ++dx;
        if (s[t] == 'R') --dx;
      }
      if (dx == 0 && dy == 0) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}