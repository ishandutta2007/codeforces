#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    cout << (s[0] + s[1] + s[2] == s[3] + s[4] + s[5] ? "YES" : "NO") << '\n';
  }
}