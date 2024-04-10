#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int perm[105];

ll qry(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  ll x = 0;
  // for (int i = l; i <= r; i++)
  //   for (int j = i + 1; j <= r; j++)
  //     x += (perm[i] > perm[j]);
  cin >> x;
  if (x == -1)
    exit(0);
  return x;
}

ll sol(ll le) {
  ll r = (1 + sqrt(1 + 4 * le)) / 2;
  while (1ll * r * (r - 1) / 2 <= le)
    r++;
  while (1ll * r * (r - 1) / 2 > le)
    r--;
  ll ans = r;
  if (1ll * ans * (ans - 1) / 2 != le)
    return -1;
  return ans;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // for (int i = 1; i <= n; i++)
    //   perm[i] = i;
    // int I, J, K;
    // cin >> I >> J >> K;
    // reverse(perm + I, perm + J);
    // reverse(perm + J, perm + K + 1);
    ll tot = qry(1, n);
    int low = 1, hi = n, ans = 1;
    while (low <= hi) {
      int mid = (low + hi) / 2;
      ll v = qry(1, mid);
      if (v == tot)
        ans = mid, hi = mid - 1;
      else
        low = mid + 1;
    }
    ll le = (tot - qry(1, ans - 1)) + 1;
    ll j = ans - le + 1;
    ll le2 = (qry(1, j - 1) - qry(1, j - 2)) + 1;
    cout << "! " << j - le2 << ' ' << j << ' ' << ans << endl;
  }
}