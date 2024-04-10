#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 7;
const int K = 18;
const int INF = (int) 1e9;
int n, x[N + 2], where[N], lg[N];
bool ok[N];
pair<int, int> rmq[K][N];

pair<int, int> f(pair<int, int> a, pair<int, int> b) {
  return {min(a.first, b.first), max(a.second, b.second)};
}

pair<int, int> get(int l, int r) {
  int k = lg[r - l + 1];
  return f(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}

bool okapi(int j, int i, int dist) {
  pair<int, int> it = get(j, i - 1);
  return (abs(x[j - 1] - it.first) <= dist && abs(x[j - 1] - it.second) <= dist);
}

bool check(int dist) {
  for (int step = 0; step <= 1; step++) {
    ok[1] = 0;
    ok[2] = (abs(x[1] - x[2]) <= dist);
    for (int i = 1; i <= n; i++) {
      where[i] = i;
      int l = i + 1, r = n;
      while (l <= r) {
        int m = (l + r) / 2;
        if (okapi(i, m, dist)) {
          where[i] = m;
          l = m + 1;
        } else
          r = m - 1;
      }
    }
    int mx = 0;
    if (ok[2])
      mx = where[2];
    for (int i = 3; i <= n; i++) {
      ok[i] = (mx >= i);
      if (ok[i])
        mx = max(mx, where[i]);
    }
    swap(x[1], x[2]);
    for (int i = 1; i <= n; i++) {
      if (ok[i]) {
        pair<int, int> it = get(i, n);
        if (abs(x[i - 1] - it.first) <= dist && abs(x[i - 1] - it.second) <= dist)
          return 1;
      }
    }
  }
  return 0;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x[1] >> x[2];
  n += 2;
  for (int i = 3; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 2; i <= n; i++)
    lg[i] = 1 + lg[i / 2];
  for (int i = 1; i <= n; i++)
    rmq[0][i] = {x[i], x[i]};
  for (int k = 1; (1 << k) <= n; k++)
    for (int i = 1; i + (1 << k) - 1 <= n; i++)
      rmq[k][i] = f(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
  int l = 1, r = (int) 1e9, ans;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  cout << ans << "\n";
}