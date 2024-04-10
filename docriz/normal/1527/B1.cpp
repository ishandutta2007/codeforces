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
    string s;
    cin >> s;
    if (n % 2 == 0) {
      cout << "BOB\n";
      continue;
    }
    if (s[(n - 1) / 2] == '1') {
      cout << "BOB\n";
      continue;
    }
    int cnt = 0;
    for (auto c: s) {
      if (c == '0') {
        cnt += 1;
      }
    }
    assert(cnt >= 1);
    if (cnt <= 1) {
      cout << "BOB\n";
      continue;
    }
    cout << "ALICE\n";
  }
  return 0;
}