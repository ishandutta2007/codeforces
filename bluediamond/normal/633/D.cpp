#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n, a[N], f[N], sol, y, x[N], cur, id[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sol += (a[i] == 0);
  }
  sort(a + 1, a + n + 1);
  y = f[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[y]) {
      f[y]++;
      continue;
    }
    y++;
    a[y] = a[i];
    f[y] = 1;
  }
  n = y;
  for (int i = 1; i <= n; i++) {
    f[i]--;
    for (int j = 1; j <= n; j++) {
      if (f[j] == 0 || (a[i] == 0 && a[j] == 0)) {
        continue;
      }
      f[j]--;
      cur = 2;
      x[1] = a[i];
      x[2] = a[j];
      while (1) {
        cur++;
        x[cur] = x[cur - 1] + x[cur - 2];
        int where = lower_bound(a + 1, a + n + 1, x[cur]) - a;
        if (where == n + 1 || a[where] != x[cur] || f[where] == 0) {
          cur--;
          sol = max(sol, cur);
          while (cur >= 3) {
            f[id[cur]]++;
            cur--;
          }
          break;
        }
        id[cur] = where;
        f[where]--;
      }
      f[j]++;
    }
    f[i]++;
  }
  cout << sol << "\n";
  return 0;
}