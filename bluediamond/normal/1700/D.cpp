#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long
const int N = 200000 + 7;
int n;
int a[N];
int b[N];
int q;
int qs[N];

bool is_ok(int prefix, int t) {
  return t >= b[prefix] && t * prefix >= a[n];
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = (a[i] + i - 1) / i;
  }
  for (int i = 2; i <= n; i++) {
    b[i] = max(b[i - 1], b[i]);
  }


  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> qs[i];
  }

  for (int i = 1; i <= q; i++) {
    int t = qs[i];
    int low = 1, high = n, sol = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (is_ok(mid, t)) {
        sol = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << sol << "\n";
  }

}