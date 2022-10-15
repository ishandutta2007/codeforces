#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N = (int) 3e5 + 7;
int n;
bool ok[N];
string s, c;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> c >> s;
    bool all = 1;
    for (int i = 1; i <= n; i++) {
      ok[i] = (s[i - 1] == c[0]);
      all &= ok[i];
    }
    if (all) {
      cout << "0\n";
      continue;
    }
    bool done = 0;
    for (int x = 1; x <= n; x++) {
      bool e = 1;
      for (int i = x; i <= n; i += x) {
        e &= ok[i];
      }
      if (e) {
        done = 1;
        cout << 1 << "\n";
        cout << x << "\n";
        break;
      }
    }
    if (!done) {
      cout << 2 << "\n";
      cout << n << " ";
      for (int i = 1; i <= n; i++) {
        if (n % i != 0) {
          cout << i << " ";
        break;
        }
      }
      cout << "\n";
    }

  }

  return 0;
}