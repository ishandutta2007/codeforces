#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int a[26];
int b[26];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < 26; i++) {
      a[i] = b[i] = 0;
    }
    string s, t;
    cin >> s >> t;
    for (auto &c : s) {
      a[c - 'a']++;
    }
    for (auto &c : t) {
      b[c - 'a']++;
    }
    for (int i = 0; i < 25; i++) {
      while (a[i] > b[i] && a[i] >= k) {
        a[i] -= k;
        a[i + 1] += k;
      }
    }
    bool ok = 1;
    for (int i = 0; i < 26; i++) {
      ok &= (a[i] == b[i]);
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

}