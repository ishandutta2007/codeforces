#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5000 + 7;
int n;
int c[N];
int j;
bool ok;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    ok = 0;
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
      ok |= (c[i] != c[1]);
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 2; i <= n; i++) {
      if (c[i] != c[1]) {
        cout << 1 << " " << i << "\n";
        j = i;
      }
    }
    for (int i = 2; i <= n; i++) {
      if (c[i] == c[1]) {
        cout << j << " " << i << "\n";
      }
    }
  }
}