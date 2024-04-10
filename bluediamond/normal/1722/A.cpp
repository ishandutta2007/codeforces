#include <bits/stdc++.h>
using namespace std;

string K = "Timur";

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = (n == 5);
    for (char c: K) {
      if (find(s.begin(), s.end(), c) == s.end()) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}