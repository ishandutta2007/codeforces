#include <bits/stdc++.h>

using namespace std;

const int N = 300000;
int v[N];
bool pos[N];
int n, k;

bool puc(int t) {
  for (int i = 0; i < n; ++i) pos[i] = false;
  set<int> bons;
  bons.insert(n);
  for (int i = n - 1; i >= 0; --i) {
    int p = upper_bound(v, v + n, t + v[i]) - v;
    // i + 1, ..., p poden ser el seguent
    if (p - i < k) continue;
    auto it = bons.lower_bound(i + k);
    if (it == bons.end() or *it > p) continue;
    bons.insert(i);
  }
  return bons.count(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v, v + n);
  int l = 0, r = 1e9 + 5;
  if (puc(0)) {
    cout << 0 << endl;
    return 0;
  }
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (puc(m)) r = m;
    else l = m;
  }
  cout << r << endl;
}