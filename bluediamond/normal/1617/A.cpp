#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen ("input", "r", stdin);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t, sol = "";
    cin >> s >> t;
    map<char, int> f;
    for (auto &x : s) {
      f[x]++;
    }
    if (t == "abc" && f.count('a') && f.count('b') && f.count('c')) {
      t = "acb";
    } else {
      t = "abc";
    }
    for (auto &ch : t) {
      for (int j = 1; j <= f[ch]; j++) {
        cout << ch;
      }
    }
    for (char c = 'd'; c <= 'z'; c++) {
      for (int j = 1; j <= f[c]; j++) {
        cout << c;
      }
    }
    cout << "\n";
  }
  return 0;
}