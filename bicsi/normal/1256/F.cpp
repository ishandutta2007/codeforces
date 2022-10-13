#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    
    string sa = a, sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    
    if (sa != sb) {
      cout << "NO\n";
      continue;
    }
    
    bool easy = false;
    for (int i = 1; i < n; ++i) {
      if (sa[i] == sa[i - 1]) {
        easy = true;
      }
    }

    if (easy) {
      cout << "YES\n";
      continue;
    }

    bool chk = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] > a[j]) chk ^= 1;
        if (b[i] > b[j]) chk ^= 1;
      }
    }

    if (chk) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}