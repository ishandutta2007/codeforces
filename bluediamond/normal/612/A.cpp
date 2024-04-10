#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
int n, a, b;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> a >> b >> s;
  /// x * a + y * b = n
  /// y * b = n - x * a
  /// y = (n - x * a) / b

  for (int x = 0; x <= n; x++) {
    if (n - x * a >= 0 && (n - x * a) % b == 0) {
      int y = (n - x * a) / b;
      cout << x + y << "\n";

      vector <string> sol;
      int i = 0;
      for (int j = 0; j < x; j++) {
        string cur;
        for (int k = 0; k < a; k++) {
          cur += s[i++];
        }
        sol.push_back(cur);
      }
      for (int j = 0; j < y; j++) {
        string cur;
        for (int k = 0; k < b; k++) {
          cur += s[i++];
        }
        sol.push_back(cur);
      }
      for (auto &x : sol) {
        cout << x << "\n";
      }
      return 0;
    }
  }
  cout << "-1\n";

  return 0;
}