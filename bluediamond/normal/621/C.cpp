#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, p;
  cin >> n >> p;
  vector<ld> prob(n);
  for (int i = 0; i < n; i++) {
    int l, r, cnt;
    cin >> l >> r;
    cnt = r / p - (l - 1) / p;
    prob[i] = (ld) cnt / (ld) (r - l + 1);
  }
  ld sol = 0;
  for (int i = 0; i < n; i++) {
    ld p1 = 1 - prob[i], p2 = 1 - prob[(i + 1) % n];
    sol += 2000 * (1 - p1 * p2);
  }
  cout << fixed << setprecision(6) << sol << "\n";
}