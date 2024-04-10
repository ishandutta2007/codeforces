#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
const int N = (int) 2e5 + 7;
int sy, n, q;
ld a, b, x[N], y[N], l[N], r[N], sum_r[N], sum_l[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("iron_man.txt", "r", stdin);
  cin >> sy >> a >> b >> n;
  sy *= -1;
  for (int i = 1; i <= n; i++) {
    int _, __;
    cin >> _ >> __;
    l[i] = _, r[i] = __;
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int _, __;
    cin >> _ >> __;
    x[i] = _, y[i] = __;
  }
  for (int i = 1; i <= n; i++) {
    sum_l[i] = sum_l[i - 1] + l[i];
    sum_r[i] = sum_r[i - 1] + r[i];
  }

  for (int i = 1; i <= q; i++) {
    ld sol = 0;

    int last = 0, first = n + 1, low = 1, high = n;
    while (low <= high) {
      int j = (low + high) / 2;
      ld x3_l = l[j] - (x[i] - l[j]) / y[i] * sy;
      ld x3_r = r[j] - (x[i] - r[j]) / y[i] * sy;
      if (x3_l <= b) {
        last = j;
        low = j + 1;
      } else {
        high = j - 1;
      }
    }
    low = 1, high = n;
    while (low <= high) {
      int j = (low + high) / 2;
      ld x3_l = l[j] - (x[i] - l[j]) / y[i] * sy;
      ld x3_r = r[j] - (x[i] - r[j]) / y[i] * sy;
      if (x3_r >= a) {
        first = j;
        high = j - 1;
      } else {
        low = j + 1;
      }
    }
    low = 1, high = n;
    int where_me = 0;
    while (low <= high) {
      int j = (low + high) / 2;

      ld x3_r = r[j] - (x[i] - r[j]) / y[i] * sy;
      if (x3_r <= b) {
        where_me = j;
        low = j + 1;
      } else {
        high = j - 1;
      }
    }
    sol += b * max(0, last - where_me);
    if (first <= where_me) {

      sol += (sum_r[where_me] - sum_r[first - 1]) * (sy / y[i]);
      sol -= (x[i] / y[i] * sy) * (where_me - first + 1);
      sol += sum_r[where_me] - sum_r[first - 1];
    }
    low = 1, high = n;
    where_me = 0;
    while (low <= high) {
      int j = (low + high) / 2;

      ld x3_l = l[j] - (x[i] - l[j]) / y[i] * sy;
      if (x3_l <= a) {
        where_me = j;
        low = j + 1;
      } else {
        high = j - 1;
      }
    }

    if (where_me + 1 <= last) {
      sol -= (sum_l[last] - sum_l[where_me]) * (sy / y[i]);
      sol += (x[i] / y[i] * sy) * (last - where_me);
      sol -= sum_l[last] - sum_l[where_me];
    }
    sol -= a * max(0, where_me - first + 1);
    cout << fixed << setprecision(6) << sol << "\n";
  }
}