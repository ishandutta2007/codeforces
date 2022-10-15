#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    set<char> f;
    for (int i = 0; i < 2; i++) {
      string s;
      cin >> s;
      assert((int) s.size() == 2);
      f.insert(s[0]);
      f.insert(s[1]);
    }
    cout << (int) f.size() - 1 << "\n";
  }
  return 0;
}