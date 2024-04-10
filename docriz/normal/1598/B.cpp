#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> can(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> can[i][j];
      }
    }
    bool ok = false;
    for (int first = 0; first < 5; first++) {
      for (int second = first + 1; second < 5; second++) {
        int count_both = 0;
        int count_first = 0;
        int count_second = 0;
        for (int i = 0; i < n; i++) {
          if (can[i][first] && can[i][second]) {
            count_both += 1;
          } else {
            if (can[i][first]) {
              count_first += 1;
            }
            if (can[i][second]) {
              count_second += 1;
            }
          }
        }
        count_first = min(count_first, n / 2);
        count_second = min(count_second, n / 2);
        if (count_first + count_second + count_both >= n) {
          ok = true;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}