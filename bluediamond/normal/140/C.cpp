#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, a[N];
map<int, int> f;

bool ok(int x) {
  n = 0;
  for (auto &it : f) {
    int border = min(it.second, x);
    for (int j = 1; j <= border; j++) {
      a[++n] = it.first;
    }
  }
  return (n >= 3 * x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    f[x]++;
  }
  int l = 1, r = n / 3, ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m)) {
      ans = m;
      l = m + 1;
    } else r = m - 1;
  }
  ok(ans);
  cout << ans << "\n";
  for (int i = 1; i <= ans; i++) {
    cout << a[2 * ans + i] << " " << a[ans + i] << " " << a[i] << "\n";
  }
}