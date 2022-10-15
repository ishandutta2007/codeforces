#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
const int N = (int) 2e5 + 7;
int n, l, x[N], y[N];

int rep(int x) {
  x %= n;
  if (x < 0) x += n;
  return x;
}

int cnt[N];

int geta(int i) {
  return x[i % n] + i / n * l;
}

int getb(int i) {
  return y[i % n] + i / n * l;
}

bool ok(int d) {
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  int j1 = 0, j2 = 0;
  for (int i = 3 * n; i < 4 * n; i++) {
    while (j2 + 1 < 6 * n && getb(j2 + 1) <= geta(i) + d) j2++;
    while (getb(j1) < geta(i) - d) {
      j1++;
    }
    if (j1 <= j2) {
      j1 *= -1;
      j2 *= -1;
      swap(j1, j2);
      int st = rep(i + j1), dr = rep(i + j2);
      st++;
      dr++;
      if (st <= dr) {
        cnt[st]++;
        cnt[dr + 1]--;
      } else {
        cnt[st]++;
        cnt[1]++;
        cnt[dr + 1]--;
      }
      j1 *= -1;
      j2 *= -1;
      swap(j1, j2);
    }
  }
  for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n; i++) if (cnt[i] == n) return 1;
  return 0;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> y[i];
  sort(x, x + n);
  sort(y, y + n);
  int lo = 0, hi = l - 1, ret = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid)) {
      ret = mid, hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ret << "\n";
}