#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> frq(k + 1, 0);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; frq[x] += 1;
  }
  for (int i = 0; i < k; ++i) {
    frq[i + 1] += frq[i] / (i + 1);
    frq[i] %= (i + 1);
    if (frq[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}