#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

struct T {
  int type, len;
};

bool operator < (T a, T b) {
  if (a.type != b.type) return a.type < b.type;
  return a.len > b.len;
}

const int N = (int) 1e6 + 7;
bitset<N> b;
int n, k, p[N], nr[N];
bool vis[N];

signed realMain() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  int doi = 0, unu = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    int j = i, cnt = 0;
    while (!vis[j]) {
      cnt++;
      vis[j] = 1;
      j = p[j];
    }
    nr[cnt]++;
    doi += cnt / 2;
    unu += cnt % 2;
  }
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int bit = 0; (1 << bit) <= nr[i]; bit++) {
      nr[i] -= (1 << bit);
      int x = (1 << bit) * i;
      b |= (b << x);
    }
    if (nr[i]) {
      int x = nr[i] * i;
      b |= (b << x);
    }
  }
  int ret = 0;
  int take_doi = min(k, doi);
  int take_one = min(k - take_doi, unu);
  ret = take_doi * 2 + take_one;
  cout << k + !b[k] << " " << ret << "\n";
  return 0;
}