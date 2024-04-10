#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n;
int k;
int a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("___input___", "r", stdin);

  const int inf = (int) 1e9 + 7;

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> n >> k;
    ll fix = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      fix += a[i];
      a[i] += i;
    }
    for (int j = 1; j <= k; j++) {
      fix += n - (k + 1 - j) + 1;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    ll sub = 0;
    for (int i = 1; i <= k; i++) {
      sub += a[i];
    }
    cout << fix - sub << "\n";
  }


  return 0;
}