#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n, a, b; cin >> n >> a >> b;
    string r(n, '.');
    for (int i = 0; i < n; ++i) {
      r[i] = (i < b) ? 'a' + i : r[i - b];
    }
    cout << r << '\n';
  }
  return 0;
}