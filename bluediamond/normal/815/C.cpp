#include <bits/stdc++.h>

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
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}


const int N = 5000 + 7;
const int INF = (int) 1e18;
int n, b, cost[N], disc[N], cu[N][N], sub[N]; /// dp[node][cnt] = min pay
vector<int> g[N];
vector<int> so;

void baga(int a) {
  so.push_back(cost[a]);
  for (auto &b : g[a]) {
    baga(b);
  }
}
int nw[N];

void dfs2(int a) {
  cu[a][0] = 0;
  cu[a][1] = cost[a] - disc[a];
  int cur = 1;
  for (auto &b : g[a]) {
    dfs2(b);
    for (int bef = cur; bef >= 1; bef--) {
      for (int now = sub[b]; now >= 0; now--) {
        cu[a][bef + now] = min(cu[a][bef + now], cu[a][bef] + cu[b][now]);
      }
    }
    cur += sub[b];
  }
  sub[a] = cur;
  so.clear();
  baga(a);
  sort(so.begin(), so.end());
  int sum = 0;
  for (int j = 0; j <= sub[a]; j++) {
    cu[a][j] = min(cu[a][j], sum);
    if (j < sub[a]) sum += so[j];
  }
}

signed realMain() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cu[i][j] = INF;
    }
  }
  cin >> n >> b;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i] >> disc[i];
    if (i >= 2) {
      int j;
      cin >> j;
      assert(1 <= j && j < i);
      g[j].push_back(i);
    }
  }
  dfs2(1);
  int cnt = 0;
  while (cnt + 1 <= n && cu[1][cnt + 1] <= b) cnt++;
  cout << cnt << "\n";
  return 0;
}