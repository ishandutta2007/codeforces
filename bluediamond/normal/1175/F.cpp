#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937 rng((long long) (new char));
const int N = (int) 3e5 + 7;
const int K = 19;
int n;
int a[N];
int t[N];
int lg[N];
int pre[N];
pair<int, int> rmq[K][N];

int ok(int l, int r) {
  return (pre[r] ^ pre[l - 1]) == t[r - l + 1];
}

int mx_id(int l, int r) {
  int k = lg[r - l + 1];
  return max(rmq[k][l], rmq[k][r - (1 << k) + 1]).second;
}

int get(int l, int r) {

  if (l > r) {
    return 0;
  }
  if (l == r) {
    return ok(l, l);
  }
  int m = mx_id(l, r), x = a[m], ret = 0;
  if (m - l + 1 < r - m) {
    for (int j = l; j <= m; j++) {
      if (j + x - 1 >= m) {
        ret += ok(j, j + x - 1);
      }
    }
  } else {
    for (int j = m; j <= r; j++) {
      if (j - x + 1 <= m) {
        ret += ok(j - x + 1, j);
      }
    }
  }
  return get(l, m - 1) + get(m + 1, r) + ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    lg[i] = 1 + lg[i / 2];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    t[i] = rng();
    rmq[0][i] = {a[i], i};
  }
  for (int k = 1; k <= lg[n]; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      rmq[k][i] = max(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
    }
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] ^ t[a[i]];
  }
  for (int i = 1; i <= n; i++) {
    t[i] ^= t[i - 1];
  }
  cout << get(1, n) << "\n";
}