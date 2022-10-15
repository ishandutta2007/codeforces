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

const int N = (int) 3e5 + 7;
const int INF = (int) 1e9;
int n, a[2][N], dp[N], nxt[2][2][N], grow[2][N], far[2];
vector<vector<int>> opt[N];

void add(int len1, int len2, int depe) {
  if (len1 > n || len2 > n) return;
  ///cout << "yay : " << len1 << " " << len2 << " -> " << depe << "\n";
  dp[max(len1, len2)] = max(dp[max(len1, len2)], depe);
  opt[min(len1, len2)].push_back({len1, len2, depe});
}

void push(int len1, int len2, int depe) {
  if (len1 > n || len2 > n) return;

  add(len1 + 1, len2, depe);
  add(len1, len2 + 1, depe);

  if (len1 == len2) {
    add(len1 + 1, len2 + 1, depe);
  }

  add(nxt[0][0][len1 + 1], len2, depe + 1);
  add(len1, nxt[1][1][len2 + 1], depe + 1);
  if (len1 == len2) {
    add(nxt[0][1][len1 + 1], nxt[0][1][len1 + 1], depe + 1);
  }

}

signed realMain() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < N; k++) {
        nxt[i][j][k] = INF;
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      grow[i][j] = INF;
    }
  }
  cin >> n;
  for (int r = 0; r <= 1; r++) {
    for (int i = 1; i <= n; i++) {
      cin >> a[r][i];
    }
  }
  for (int lo = 0; lo <= 1; lo++) {
    for (int hi = lo; hi <= 1; hi++) {
      map<int, int> last;
      int sum = 0;
      last[0] = n + 1;
      for (int i = n; i >= 1; i--) {
        for (int r = lo; r <= hi; r++) {
          sum += a[r][i];
        }
        if (last.count(sum)) {
          nxt[lo][hi][i] = last[sum] - 1;
        }
        last[sum] = i;
      }
    }
  }
  for (int i = 0; i + 1 <= n; i++) {
    push(i, i, dp[i]);
    far[0] = far[1] = N;
    for (auto &it : opt[i]) {
      if (it[2] == dp[i] + 1) {
        assert(it[0] == i || it[1] == i);
        if (it[1] == i) far[0] = min(far[0], it[0]);
        else far[1] = min(far[1], it[1]);
      }
    }
    push(far[0], i, dp[i] + 1);
    push(i, far[1], dp[i] + 1);
  }
  cout << dp[n] << "\n";
  return 0;
}