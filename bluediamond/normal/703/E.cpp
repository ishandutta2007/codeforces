#include <bits/stdc++.h>

using namespace std;

#define int long long

struct T {
  int cnt;
  int sum;
  int last;
  int pxp;
};

T lol;

const int N = 1000 + 7;
const int INF = (int) 1e18;
int n, k, sz;
vector<T> dp[N];
vector<int> d;

int getid(int x) {
  int l = 0, r = sz - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (d[m] == x) return m;
    if (d[m] < x) l = m + 1;
    else r = m - 1;
  }
  assert(0);
}

T operator + (T a, int x) {
  a.cnt++;
  a.sum += x;
  return a;
}

int now, uu;

void upd(T &a, T b) {
  if (b.cnt < a.cnt) {a = b; a.last = now; a.pxp = uu; return;}
  if (b.cnt == a.cnt && b.sum < a.sum) {a = b; a.last = now; a.pxp = uu; return;}
}

int a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  lol.cnt = INF, lol.sum = INF;

  cin >> n >> k;
  if (k == 1) {
    int mnid = -1, mn = INF;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      mn = min(mn, x);
      if (mn == x) mnid = i;
    }
    cout << "1\n" << mnid << "\n";
    return 0;
  }
  for (int i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      d.push_back(i);
      if (i * i == k) break;
      d.push_back(k / i);
    }
  }
  sort(d.begin(), d.end());
  sz = (int) d.size();
  dp[0].resize(sz, lol);
  dp[0][0] = {0, 0, 0};
  for (int i = 1; i <= n; i++) {
    now = i;
    cin >> a[i];
    dp[i] = dp[i - 1];
    int nw = __gcd(a[i], k);
    if (nw == 1) continue;
    for (int j = 0; j < sz; j++) {

      if (dp[i - 1][j].cnt == INF) continue;
      uu = j;
      int g = __gcd((__int128)(d[j] * nw), (__int128)k);
      int id = getid(g);
      upd(dp[i][id], dp[i - 1][j] + a[i]);
    }
  }
  if (dp[n].back().cnt == INF) {
    cout << "-1\n";
    return 0;
  }
  cout << dp[n].back().cnt << "\n";

  int i = n, j = sz - 1;
  for (int step = 1; step <= dp[n].back().cnt; step++) {
    cout << dp[i][j].last << " ";
    int in = dp[i][j].last - 1, jn = dp[i][j].pxp;
    i = in;
    j = jn;
  }
  cout << "\n";

 /// cout << dp[n].back().last << "\n";

  ///cout << dp[n].back().cnt << " " << dp[n].back().sum << "\n";
}