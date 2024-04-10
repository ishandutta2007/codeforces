#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n, 0), d(n, 0);
    ll sol = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sol += a[i];
    }
    vector<int> g;
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      d[x]++;
      d[y]++;
      if (d[x] >= 2) {
        g.push_back(a[x]);
      }
      if (d[y] >= 2) {
        g.push_back(a[y]);
      }
    }
    sort(g.begin(), g.end());
    cout << sol << " ";
    for (int i = 0; i < n - 2; i++) {
      sol += g.back();
      g.pop_back();
      cout << sol << " ";
    }
    cout << "\n";
  }
}