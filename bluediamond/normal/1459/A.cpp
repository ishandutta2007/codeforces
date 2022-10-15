#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, w1 = 0, w2 = 0;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
      int x = s[i] - '0', y = t[i] - '0';
      w1 += (x > y);
      w2 += (x < y);
    }
    if (w1 > w2) {
      cout << "RED\n";
    } else {
      if (w1 < w2) {
        cout << "BLUE\n";
      } else {
        cout << "EQUAL\n";
      }
    }
  }
}