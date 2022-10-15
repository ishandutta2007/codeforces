#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

set<int> s;

void dfs(int a) {
  if (a > 100000 || s.count(a)) return;
  s.insert(a);
  int x = 11;
  for (int j = 1; j <= 4; j++) {
    dfs(a + x);
    x = 10 * x + 1;
  }
}

const int N = 100 + 7;
int n, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  dfs(0);
  /**
  int ind = 0, ant = 0;
  for (auto &it : s) {
    cout << it << " : " << it - ant << "\n";
    if (it >= 2000) assert(it - ant == 1);

    ant = it;
  }
  return 0;**/

  /// freopen ("input", "r", stdin);


  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n >= 10000) {
      cout << "YES\n";
    } else {
      if (s.count(n)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
}