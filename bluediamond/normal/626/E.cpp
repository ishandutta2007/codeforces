#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200000 + 7;
int n;
int v[N];
ll sum[N];
ld sol = -1;
int index;
int tt;

ll evalint(int i, int t) {
  return (sum[n] - sum[n - t] + sum[i] - sum[i - t - 1]);
}

ld get(int i, int t) {
  return evalint(i, t) / (ld) (2 * t + 1) - v[i];
}

void upd(int i, int t) {
  ld cur = get(i, t);
  if (cur > sol) {
    sol = cur;
    index = i;
    tt = t;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  cin >> n;
  if (n <= 2) {
    cout << "1\n";
    int foo;
    cin >> foo;
    cout << foo << "\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + v[i];
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = min(i - 1, n - i);
    while (l <= r) {
      int m = (l + r) / 2;
      upd(i, m);
      if (m == r) {
        r = m - 1;
      } else {
        if (get(i, m) > get(i, m + 1)) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
  }
  cout << (2 * tt + 1) << "\n";
  for (int j = index - tt; j <= index; j++) {
    cout << v[j] << " ";
  }
  for (int j = n - tt + 1; j <= n; j++) {
    cout << v[j]<< " ";
  }
  cout << "\n";
  return 0;
}