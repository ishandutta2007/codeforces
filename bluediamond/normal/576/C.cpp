#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int>> a[1000 + 7];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a[x / 1000].push_back({y, i});
  }

  int now = 0;
  for (int i = 0; i <= 1000; i++) {
    if (!a[i].empty()) {
      now++;
      sort(a[i].begin(), a[i].end());
      if (now & 1) {
        reverse(a[i].begin(), a[i].end());
      }
      for (auto &it : a[i]) {
        cout << it.second << " ";
      }
    }
  }
  cout << "\n";

  return 0;
}