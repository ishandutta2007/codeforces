#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 2e5 + 7;
int n, a[N], sum;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      a[i] *= n;
    }
    sum *= 2;

    map<int, int> fr;

    int sol = 0;

    for (int i = 1; i <= n; i++) {
      sol += fr[sum - a[i]];
      fr[a[i]]++;
    }
    cout << sol << "\n";

  }

  return 0;
}