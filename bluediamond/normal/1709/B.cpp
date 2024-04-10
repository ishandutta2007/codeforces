#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = (int) 1e5 + 7;
int n, q, a[N], d1[N], d2[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    d1[i] = d1[i - 1] + max(a[i] - a[i + 1], 0LL);
    d2[i] = d2[i - 1] + max(a[i] - a[i - 1], 0LL);
  }
  while (q--) {
    int from, to;
    cin >> from >> to;
    if (from < to) {
      cout << d1[to - 1] - d1[from - 1] << "\n";
    } else {
      cout << d2[from] - d2[to] << "\n";
    }
  }
}