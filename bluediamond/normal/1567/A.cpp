#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
int n, block[N];
string s;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      block[i] = (s[i - 1] == 'U' || s[i - 1] == 'D');
    }
    int i = 1;
    while (i <= n) {
      if (block[i]) {
        cout << (char) (('D' + 'U') - s[i - 1]);
        i += 1;
      } else {
        cout << "LR";
        i += 2;
      }
    }
    cout << "\n";
  }
}