#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; ++qq) {
    int n, h;
    cin >> h >> n;
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    int r = 1, answer = 0;
    while (r + 1 <= n) {
      if (p[r] - 1 == p[r + 1]) r += 2;
      else answer += 1, r += 1;
    }
    cout << answer << endl;
  }
  return 0;
}