#include <bits/stdc++.h>

using namespace std;

///#define int ll
typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = 0;
    for (auto &ch : s) {
      n += (ch == 'N');
    }
    if (n == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}