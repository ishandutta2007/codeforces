#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();

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

const int N = 1500 + 7;
const int Q = 12;
int n, k, a[N][N], ret[N];
pair<int, int> things[N][N][Q];
bool acum[N * N];

signed realMain() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      vector<pair<int, int>> guys;
      guys.push_back({1, a[i][j]});
      if (i >= 2) {
        for (int t = 1; t <= k + 1 && things[i - 1][j][t].first; t++) {
          guys.push_back({things[i - 1][j][t].first + 1, things[i - 1][j][t].second});
        }
      }
      if (j >= 2) {
        for (int t = 1; t <= k + 1 && things[i][j - 1][t].first; t++) {
          guys.push_back({things[i][j - 1][t].first + 1, things[i][j - 1][t].second});
        }
      }
      if (i >= 2 && j >= 2) {
        for (int t = 1; t <= k + 1 && things[i - 1][j - 1][t].first; t++) {
          guys.push_back({things[i - 1][j - 1][t].first + 1, things[i - 1][j - 1][t].second});
        }
      }
      sort(guys.begin(), guys.end());
      int cnt = 0;
      for (auto &x : guys) {
        if (acum[x.second]) continue;
        cnt++;
        acum[x.second] = 1;
        things[i][j][cnt] = x;
        if (cnt == k + 1) break;
      }
      for (auto &x : guys) {
        acum[x.second] = 0;
      }
      int now = min(i, j);
      if (cnt == k + 1) {
        now = min(now, things[i][j][cnt].first - 1);
      }
      ret[now]++;
    }
  }
  for (int i = n; i >= 1; i--) {
    ret[i] += ret[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << ret[i] << "\n";
  }
}