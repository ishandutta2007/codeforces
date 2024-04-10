#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    cin >> s;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (a[i] == a[j] && s[i] != s[j]) ok = 0;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}