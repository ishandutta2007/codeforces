#include <bits/stdc++.h>
using namespace std;

bool in(int x, int y, const tuple<int, int, int, int> &s) {
  int a, b, c, d;
  tie(a, b, c, d) = s;
  if (a == c && b == d) return a == x && b == y;
  else if (a == c) return a == x && b <= y && y <= d;
  else return b == y && a <= x && x <= c;
}
vector<tuple<int, int, int, int>> strokes;

bool solve() {
  static char s[2222][2222];
  static int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  vector<pair<int, int>> a[26];
  int kind = -1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (s[i][j] != '.') {
        int idx = s[i][j] - 'a';
        a[idx].emplace_back(i, j);
        kind = max(kind, idx);
      }
  strokes.clear();
  if (kind == -1) return true;
  for (int i = 0; i <= kind; ++i) {
    if (a[i].empty()) {
      strokes.emplace_back(a[kind][0].first, a[kind][0].second,
                           a[kind][0].first, a[kind][0].second);
    }
    else {
      if (a[i].front().first != a[i].back().first &&
          a[i].front().second != a[i].back().second)
        return false;
      strokes.emplace_back(a[i].front().first, a[i].front().second,
                           a[i].back().first, a[i].back().second);
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (s[i][j] != '.') {
        int idx = s[i][j] - 'a';
        for (int k = kind; k > idx; --k) if (in(i, j, strokes[k])) return false;
        if (!in(i, j, strokes[idx])) return false;
      } else {
        for (auto &it : strokes) if (in(i, j, it)) return false;
      }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int _ = 0; _ < T; ++_) {
    if (solve()) {
      puts("YES");
      printf("%d\n", int(strokes.size()));
      for (auto &it : strokes) {
        int a, b, c, d;
        tie(a, b, c, d) = it;
        printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);
      }
    } else {
      puts("NO");
    }
  }
  return 0;
}