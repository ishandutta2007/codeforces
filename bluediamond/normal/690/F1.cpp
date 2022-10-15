#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e4 + 7;
int n, d[N], sol;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    sol += d[x]++;
    sol += d[y]++;
  }
  cout << sol << "\n";

  return 0;
}