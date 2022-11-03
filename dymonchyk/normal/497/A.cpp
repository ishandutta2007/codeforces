#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[1002][1002];
int what[1002];

int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i) {
    gets(f[i]);
  }
  int ans = 0;
  for (int it = 0; it < m; ++it) {
    bool ok = true;
    for (int i = 1; i < n; ++i)
      if (what[i] == what[i - 1]) ok = false;
    if (ok) break;
    int cnt = 0, tmp[1002] = {0}, good = 1;
    for (int i = 1; i < n; ++i) {
      if (what[i] == what[i - 1] && f[i][it] < f[i - 1][it]) {
        good = false;
        break;
      }
    }
    if (good) {
      for (int i = 1; i < n; ++i) {
        if (what[i] != what[i - 1] || f[i][it] > f[i - 1][it]) {
          ++cnt;
        }
        tmp[i] = cnt;
      }
      for (int i = 0; i < n; ++i)
        what[i] = tmp[i];
    } else {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}