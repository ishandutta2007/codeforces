#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(vector<int> a, double bound, double k) {
  double need = 0, have = 0;
  for (auto &pintx : a) {
    double x = pintx;
    if (x > bound) {
      have += x - bound;
    } else {
      need += bound - x;
    }
  }
  have *= k;
  return (have >= need);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  double k;
  cin >> n >> k;
  k = (1.0 - k / 100.0);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double l = 0, r = 1e9;
  for (int steps = 1; steps <= 100; steps++) {
    double mid = (l + r) * 0.5;
    if (check(a, mid, k)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(6) << l << "\n";
}