#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    char c = 'a';
    for (int i = 1; i <= n; i++) {
      cout << c;
      if (i % k == 0) c++;
      if (c == 'd') c = 'a';
    }
    cout << "\n";
  }

}