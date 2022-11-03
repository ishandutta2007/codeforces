#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> v;
vector<int> what[300002];
bool used[300002];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int ptr = 0, ans = 0, cnt = 0;
  for (int i = 1; i <= q; ++i) {
    int t, x;
    scanf("%d%d", &t, &x);
    if (t == 1) {
      what[x].push_back(++cnt);
      ++ans;
    } else if (t == 2) {
      for (int j = what[x].size() - 1; j >= 0; --j) {
        if (!used[what[x][j]]) {
          --ans;
          used[what[x][j]] = true;
        } else {
          break;
        }
      }
    } else {
      while (ptr + 1 <= x) {
        ++ptr;
        if (!used[ptr]) --ans;
        used[ptr] = true;
      }
    }
    cout << ans << endl;
  }
  return 0;
}