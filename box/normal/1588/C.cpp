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

vector<ll> b[2];
vector<ll> bz[2][20];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n), dif(n + 10), alta(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      alta[i] = a[i];
      if (i % 2)
        alta[i] = -a[i];
      if (i) {
        alta[i] += alta[i - 1];
        dif[i] = a[i] - a[i - 1];
      }
    }
    int n2 = n / 2 + 1;
    vector<ll> bb(2 * n2);
    b[0] = b[1] = vector<ll>(n2);
    for (int i = 0; i < n2; i++)
      b[0][i] = dif[i * 2] + (i ? b[0][i - 1] : 0),
      b[1][i] = dif[i * 2 + 1] + (i ? b[1][i - 1] : 0);
    for (int i = 0; i < n2; i++)
      bb[i * 2] = b[0][i], bb[i * 2 + 1] = b[1][i];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 20; j++)
        bz[i][j] = vector<ll>(n2, -1e18);
    bz[0][0] = b[0], bz[1][0] = b[1];
    for (int p = 0; p < 2; p++)
      for (int j = 1; j < 20; j++)
        for (int i = 0; i < n2 - (1 << (j - 1)); i++)
          bz[p][j][i] = min(bz[p][j - 1][i], bz[p][j - 1][i + (1 << (j - 1))]);
    ll ans = 0;
    vector<vector<pii>> qrys(n);
    for (int i = 0; i < n; i++) {
      int re;
      ll sth = bb[i] - a[i], dth = 0;
      if (i)
        dth = bb[i - 1];
      if (i % 2 == 0) {
        int r1 = i, r2 = i + 1;
        for (int j = 19; j >= 0; j--) {
          if (r1 <= n && bz[0][j][r1 / 2] >= sth)
            r1 += 2 * (1 << j);
          if (r2 <= n && bz[1][j][r2 / 2] >= dth)
            r2 += 2 * (1 << j);
        }
        re = min(r1, r2);
      } else {
        int r1 = i + 1, r2 = i;
        for (int j = 19; j >= 0; j--) {
          if (r1 <= n && bz[0][j][r1 / 2] >= dth)
            r1 += 2 * (1 << j);
          if (r2 <= n && bz[1][j][r2 / 2] >= sth)
            r2 += 2 * (1 << j);
        }
        re = min(r1, r2);
      }
      re = min(n, re);
      if (a[i] == 0)
        ans++;
      ll q = 0;
      if (i)
        q = alta[i - 1];
      qrys[re - 1].pb({q, 1});
      qrys[i].pb({q, -1});
    }
    map<ll, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[alta[i]]++;
      for (auto [a, x] : qrys[i])
        ans += x * cnt[a];
    }
    cout << ans << endl;
  }
}