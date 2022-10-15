#include <bits/stdc++.h>

using namespace std;

const int N = 400000;
const int A = 32;
int p[A];
int n, b[N], a[N];

int get(int p) {
  /// a[i] + a[j] <= p
  /// a[j] <= p - a[i]
  int sol = 0;
  for (int i = 0; i < n; i++) {
    int l = 0, r = i - 1, ans = 0;
    while (l <= r) {
      int md = (l + r) / 2;
      if (a[md] <= p - a[i]) {
        ans = md + 1;
        l = md + 1;
      } else {
        r = md - 1;
      }
    }
    sol += ans % 2;
  }
  return sol % 2;
}

int get(int l, int r) {
  return get(r) - get(l - 1) + 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int bt = 0; bt < A; bt++) {
    p[bt] = (1 << bt);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int sol = 0;
  for (int bt = 0; bt + 2 < A; bt++) {
    for (int i = 0; i < n; i++) {
      a[i] = b[i] % p[bt + 1];
    }
    sort(a, a + n);
    int cnt = get(p[bt], p[bt + 1] - 1) + get(p[bt + 1] + p[bt], p[bt + 2] - 2);
    if (cnt & 1) {
      sol += (1 << bt);
    }
  }
  cout << sol << "\n";
}