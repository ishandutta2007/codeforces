#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto &ch : s) {
      a += (ch == 'A');
      b += (ch == 'B');
      c += (ch == 'C');
    }
    if (a + c == b) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}