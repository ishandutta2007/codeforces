#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
int n;
int a[N];
int pre[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    int sol = 0;
    for (int i = 2; i <= n; i++) {
      sol -= a[i] * (i - 2);
      sol += pre[i - 2];
    }
    cout << sol << "\n";
  }
  return 0;
}