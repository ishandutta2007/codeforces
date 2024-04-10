#include <bits/stdc++.h>

using namespace std;

char g(char c) {
  if (c == '2') {
    return '1';
  } else {
    return '0';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s, a = "1", b = "1";
    cin >> n >> s;
    int i = 0;
    while (i + 1 < n && s[i + 1] != '1') {
      i++;
      a += g(s[i]);
      b += g(s[i]);
    }
    i++;
    if (i < n) {
      a += "1";
      b += "0";
      for (int j = i + 1; j < n; j++) {
        /// minimizez a
        a += "0";
        b += s[j];
      }
    }
    cout << a << "\n";
    cout << b << "\n";
  }

}