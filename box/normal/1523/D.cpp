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

string cur[200005];
int cnt[1 << 15];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> r(n);
  iota(all(r), 0);
  mt19937 rng(108616);
  shuffle(all(r), rng);
  for (int i = 0; i < n; i++)
    cin >> cur[i];
  uint64_t gans = 0;
  for (int i = 0; i < min(100, n); i++) {
    int u = r[i];
    vector<int> yes;
    for (int p = 0; p < m; p++)
      if (cur[u][p] == '1')
        yes.push_back(p);
    memset(cnt, 0, sizeof cnt);
    int ct = yes.size();
    for (int v = 0; v < n; v++) {
      int z = 0;
      for (int p = 0; p < ct; p++)
        z = z | ((cur[v][yes[p]] == '1') << p);
      cnt[z]++;
    }
    for (int p = 0; p < ct; p++)
      for (int x = 0; x < (1 << ct); x++)
        if (x & (1 << p))
          cnt[x ^ (1 << p)] += cnt[x];
    assert(cnt[0] == n);
    int ans = 0;
    for (int x = 0; x < (1 << ct); x++)
      if (cnt[x] >= (n + 1) / 2 &&
          __builtin_popcount(x) > __builtin_popcount(ans))
        ans = x;
    if (__builtin_popcount(ans) > __builtin_popcountll(gans)) {
      gans = 0;
      for (int p = 0; p < ct; p++)
        if (ans & (1 << p))
          gans |= (1ull << yes[p]);
    }
  }
  for (int i = 0; i < m; i++)
    cout << !!(gans & (1ull << i));
  return 0;
}