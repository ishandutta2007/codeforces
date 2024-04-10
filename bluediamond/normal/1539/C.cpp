#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = (int) 2e5 + 7;
int n, k, x, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  vector<int> b;
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] != a[i]) {
      b.push_back((a[i] - a[i - 1] - 1) / x);
      cnt++;
    }
  }
  sort(b.begin(), b.end());
  for (auto &kek : b) {
    if (kek <= k) {
      cnt--;
      k -= kek;
    }
  }
  cout << cnt << "\n";





  return 0;
}