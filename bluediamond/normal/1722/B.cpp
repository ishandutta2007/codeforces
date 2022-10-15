#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    set<string> m;
    bool ok = 0;
    int k = 2;
    while (k--) {
      string s;
      cin >> s;
      for (char& c: s) {
        if (c == 'G') c = 'B';
      }
      if (m.count(s)) ok = 1;
      m.insert(s);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}