#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4 + 7;
const int INF = (int) 1e9;
int n, m, cnt, r[N], c[N], dp[N];
vector<int> row[N], col[N];
bool drow[N], dcol[N];
map<pair<int, int>, int> sol;
int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

int id(int r, int c) {return sol[{r, c}];}
struct T {
  int i, dp;
};

bool operator < (T a, T b) {
  return a.dp > b.dp;
}

priority_queue<T> q;

void dor(int r, int val) {
  if (1 <= r && r <= n && drow[r] == 0) {
    drow[r] = 1;
    for (auto &i : row[r]) {
      if (val < dp[i]) {
        dp[i] = val;
        q.push({i, val});
      }
    }
  }
}

void doc(int c, int val) {
  if (1 <= c && c <= m && dcol[c] == 0) {
    dcol[c] = 1;
    for (auto &i : col[c]) {
      if (val < dp[i]) {
        dp[i] = val;
        q.push({i, val});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> cnt;
  for (int i = 1; i <= cnt; i++) {
    cin >> r[i] >> c[i];
    row[r[i]].push_back(i);
    col[c[i]].push_back(i);
    sol[{r[i], c[i]}] = i;
    dp[i] = INF;
  }
  if (id(n, m)) {
    dp[id(n, m)] = 0;
    q.push({id(n, m), 0});
  } else {
    dor(n - 1, 1);
    dor(n, 1);
    doc(m - 1, 1);
    doc(m, 1);
  }
  while (!q.empty()) {
    int i = q.top().i, dpi = q.top().dp;
    q.pop();
    if (dpi != dp[i]) continue;
    for (int k = 0; k < 4; k++) {
      int j = id(r[i] + dr[k], c[i] + dc[k]);
      if (j && dp[i] < dp[j]) {
        dp[j] = dp[i];
        q.push({j, dp[j]});
      }
    }
    for (int r2 = r[i] - 2; r2 <= r[i] + 2; r2++) dor(r2, 1 + dp[i]);
    for (int c2 = c[i] - 2; c2 <= c[i] + 2; c2++) doc(c2, 1 + dp[i]);
  }
  int ans = dp[id(1, 1)];
  if (ans == INF) ans = -1;
  cout << ans << "\n";
}