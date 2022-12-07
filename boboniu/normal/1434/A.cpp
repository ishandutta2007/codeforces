#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 123456

int a[10], n;
int b[maxN];
set<array<int, 3>> s;

int main() {
  for (int i = 0; i < 6; i++)
    scanf("%d", &a[i]);
  sort(a, a + 6);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    s.insert({b[i] - a[5], b[i], 5});
  }
  int ans = 1.1e9;
  while (true) {
    auto r = *s.begin();
    ans = min(ans, (*--s.end())[0] - r[0]);
    s.erase(s.begin());
    if (r[2] == 0)
      break;
    s.insert({r[1] - a[r[2] - 1], r[1], r[2] - 1});
  }
  printf("%d\n", ans);
}