#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, k, a[N], f[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int nini = n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
      int l;
      cin >> l;
      f[l]++;
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    while (f[1] > 0) {
      f[1]--;
      k--;
      ans += 2LL * a[n--];
    }
    while (k > 0) {
      k--;
      ans += a[n--];
    }
    int pos = 1;
    for (int l = nini; l >= 2; l--) {
      while (f[l] > 0) {
        f[l]--;
        ans += a[pos];
        pos += l - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}