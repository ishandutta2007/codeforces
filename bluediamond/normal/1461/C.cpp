#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = (int) 1e5 + 7;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (n && a[n] == n) n--;
    ld nup = 1;
    while (q--) {
      int i;
      ld p;
      cin >> i >> p;
      if (i >= n) nup *= ((ld) 1 - p);
    }
    if (n < 1) nup = 0;
    cout << fixed << setprecision(6) << (ld) 1 - nup << "\n";
  }
}