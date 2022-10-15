#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i * a <= c; i++) {
    int r = c - i * a;
    if (r % b == 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}