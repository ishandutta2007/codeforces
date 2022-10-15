#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s;
    t = s;
    t.resize((int) t.size() / 2);
    t += t;
    cout << ((t == s) ? "YES" : "NO") << "\n";
  }
  return 0;
}