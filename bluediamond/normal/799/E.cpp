#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 200000 + 7;
const int INF = (int) 2e18;
int n, m, k, cost[N], ret = INF, pre[N], id[N];
bool l1[N], l2[N];
vector<int> s[2][2];
int c[2][2], t[2][2], cnt[N][2][2];

bool cmp(int i, int j) {
  return cost[i] < cost[j];
}

int get(int x, int y, int l, int r) {
  if (l > r) return 0;
  return s[x][y][r] - s[x][y][l - 1];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  vector<int> ord;
  for (int i = 1; i <= n; i++) {
    ord.push_back(i);
    cin >> cost[i];
  }
  sort(ord.begin(), ord.end(), cmp);
  int c1, c2;
  cin >> c1; while (c1--) {int i; cin >> i; l1[i] = 1;}
  cin >> c2; while (c2--) {int i; cin >> i; l2[i] = 1;}
  for (int i = 0; i <= 1; i++) for (int j = 0; j <= 1; j++) s[i][j].push_back(0);
  for (auto &i : ord) {
    t[l1[i]][l2[i]] += cost[i];
    c[l1[i]][l2[i]]++;
    pre[i] = t[0][0] + t[0][1] + t[1][0] + t[1][1];
    id[i] = c[l1[i]][l2[i]];
    for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) cnt[i][x][y] = c[x][y];
    s[l1[i]][l2[i]].push_back(t[l1[i]][l2[i]]);
  }
  for (int com = 0; com <= c[1][1]; com++) {
    int st = max(0LL, k - com);
    if (st > min(c[0][1], c[1][0])) continue;
    int now = s[1][1][com] + s[0][1][st] + s[1][0][st];
    int need = m - (com + 2 * st);
    if (need < 0) continue;
    if (!need) {
      ret = min(ret, now);
      continue;
    }
    int l = 0, r = n - 1, add = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      int i = ord[m];
      int numero = m + 1  - min(com, cnt[i][1][1]) - min(st, cnt[i][0][1]) - min(st, cnt[i][1][0]);
      if (numero < need) {
        l = m + 1;
        add = ord[m + 1];
      } else {
        r = m - 1;
      }
    }
    int i = add;
    ret = min(ret, now + pre[i] - s[1][1][min(com, cnt[i][1][1])] - s[0][1][min(st, cnt[i][0][1])] - s[1][0][min(st, cnt[i][1][0])]);
  }
  if (ret == INF) {
    ret = -1;
  }
  cout << ret << "\n";
}