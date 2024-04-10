#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  long long b = 0, w = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (i % 2 == 0) {
      b += x / 2;
      w += x - x / 2;
    } else {
      w += x / 2;
      b += x - x / 2;
    }
  }
  cout << min(b, w) << endl;

  return 0;
}