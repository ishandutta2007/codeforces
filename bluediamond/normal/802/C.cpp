#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
const int N = 200;
const int INF2 = (int) 1e9;
const int INF = (int) 1e18;
int n;
int k;
int s;
int d;
int a[N];
int c[N];
int cap[N][N];
int cost[N][N];
vector<int> g[N];
int best[N];
int par[N];
bool act[N];

void baga(int a, int b, int cst) {
  g[a].push_back(b);
  b[g].push_back(a);
  cap[a][b] = 1;
  cost[a][b] = cst;
  cost[b][a] = -cost[a][b];
}

signed main() {
 /// freopen ("input", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  s = 0;
  d = 2 * n + 1;
  for (int i = 1; i <= n; i++) {
    baga(2 * i - 1, 2 * i, -INF2);
    baga(s, 2 * i - 1, c[a[i]]);
    baga(2 * i, d, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int cst;
      if (a[i] == a[j]) cst = 0;
      else cst = c[a[j]];
      baga(2 * i, 2 * j - 1, cst);
    }
  }
  int nn = n;
  n = d + 1;
  int ans = 0;
  int ret = INF;
  for (int step = 1; step <= k; step++) {
    for (int i = 0; i < n; i++) {
      best[i] = INF;
    }
    act[s] = 1;
    best[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      act[a] = 0;
      for (auto &b : g[a]) {
        if (cap[a][b] > 0 && best[a] + cost[a][b] < best[b]) {
          best[b] = best[a] + cost[a][b];
          par[b] = a;
          if (act[b] == 0) {
            act[b] = 1;
            q.push(b);
          }
        }
      }
    }
    if (best[d] == INF) {
      break;
    }
    int mn = INF, now = d;
    while (now != s) {
      int a = par[now];
      int b = now;
      mn = min(mn, cap[a][b]);
      now = par[now];
    }
    ans += (ll) best[d] * mn;
    ret = min(ret, ans);
    now = d;
    while (now != s) {
      int a = par[now];
      int b = now;
      cap[a][b] -= mn;
      cap[b][a] += mn;
      now = par[now];
    }
  }
  cout << ret + nn * INF2 << "\n";
}