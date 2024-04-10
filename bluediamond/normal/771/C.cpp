#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 2e5 + 7;
const int K = 5;
int n, k, ret, root, sub[N], down[N][K], up[N][K], par[N], kek[K];
vector<int> g[N];

void build2(int a, int p = -1) {
  up[a][0] = 1;
  if (p != -1) {
    kek[0]++;
    for (int j = 0; j < k; j++) {
      kek[(j + 1) % k] += down[p][j];
    }
    kek[1]--;
    for (int j = 0; j < k; j++) {
      up[a][j] = kek[j];
      kek[j] = 0;
    }
    for (int r = 0; r < k; r++) {
      up[a][(r + 1) % k] += up[p][r];
    }
    for (int r = 0; r < k; r++) {
      up[a][(r + 2) % k] -= down[a][r];
    }
  }
  for (auto &b : g[a]) {
    if (b != p) {
      build2(b, a);
    }
  }
}

void build(int a, int p = -1) {
  par[a] = p;
  down[a][0] = 1;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b != p) {
      build(b, a);
      ret += 2 * sub[b] * (n - sub[b]);
      sub[a] += sub[b];
      for (int r = 0; r < k; r++) {
        down[a][(r + 1) % k] += down[b][r];
      }
    }
  }
}

signed realMain() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build(1);
  build2(1);
  for (int dist = 0; dist < k; dist++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += up[i][dist] + down[i][dist];
    }
    cnt -= (dist == 0) * n;
    ret -= (dist + k - 1) % k * cnt;
  }
  ret += (k - 1) * n * n;
  ret /= k;
  ret /= 2;
  cout << ret << "\n";
  if (home && n == 13) {
    assert(ret == 114);
  }
  return 0;
}