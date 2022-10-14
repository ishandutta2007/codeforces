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
const int MOD = 1042145983;

auto rng =
    mt19937(chrono::high_resolution_clock::now().time_since_epoch().count());
int base = uniform_int_distribution<int>(3, MOD - 5)(rng);

int ex[200005];
int pos[26][200005];

int ghash(int *ar, int l, int r) {
  if (l)
    return (ar[r - 1] + 1ll * (MOD - ar[l - 1]) * ex[r - l]) % MOD;
  return ar[r - 1];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ex[0] = 1, ex[1] = base;
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++)
    ex[i] = 1ll * ex[1] * ex[i - 1] % MOD;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    pos[s[i] - 'a'][i] = 1;
  for (int r = 0; r < 26; r++)
    for (int i = 0; i < n; i++)
      pos[r][i] = (1ll * (i ? pos[r][i - 1] : 0) * ex[1] + pos[r][i]) % MOD;
  while (q--) {
    int x, y, l;
    cin >> x >> y >> l;
    x--, y--;
    multiset<int> A, B;
    for (int i = 0; i < 26; i++) {
      A.insert(ghash(pos[i], x, x + l));
      B.insert(ghash(pos[i], y, y + l));
    }
    cout << (A == B ? "YES" : "NO") << endl;
  }
}