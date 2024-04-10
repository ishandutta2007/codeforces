#include <bits/stdc++.h>

using namespace std;

#define int long long

string id(string a, string b) {
  string sol;
  sol += a[0];
  sol += a[1];
  sol += b[1];
  sol += b[0];
  for (int i = 0; i < 4; i++) {
    if (sol[i] == 'A') {
      string kek;
      for (int j = 0; j < 4; j++) {
        char ch = sol[(i + j) % 4];
        if (ch != 'X') kek += ch;
      }
      return kek;
    }
  }
  assert(0);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((id(a, b) == id(c, d)) ? "YES" : "NO") << "\n";
  return 0;
}