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

vector<pii> elist[300015 * 6];
const int TH = 600005;
int TH2;
int build(int idx, int l, int r) {
  if (r - l == 1) {
    elist[idx + TH].push_back({TH2 + l, 0});
    return idx + TH;
  }
  elist[idx + TH].push_back({build(idx * 2, l, (l + r) / 2), 0});
  elist[idx + TH].push_back({build(idx * 2 + 1, (l + r) / 2, r), 0});
  return idx + TH;
}
void conn(int idx, int l, int r, int L, int R, int fro) {
  if (L <= l && r <= R) {
    elist[fro].push_back({idx + TH, 0});
    return;
  }
  if (R <= l || r <= L)
    return;
  conn(idx * 2, l, (l + r) / 2, L, R, fro);
  conn(idx * 2 + 1, (l + r) / 2, r, L, R, fro);
}
int a[300005], b[300005];
int dis[300015 * 6], pre[300015 * 6];
bool relaxed[300015 * 6];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int j = 1; j <= n; j++)
    cin >> b[j];
  TH2 = n + 1;
  for (int i = 0; i <= n; i++)
    elist[TH2 + i].push_back({i + b[i], 1});
  build(1, 0, n + 1);
  for (int i = 1; i <= n; i++)
    conn(1, 0, n + 1, i - a[i], i + 1, i);
  memset(dis, -1, sizeof dis);
  queue<int> q1, q2;
  q2.push(n);
  dis[n] = 0;
  while (q2.size()) {
    swap(q1, q2);
    assert(q2.size() == 0);
    while (q1.size()) {
      int u = q1.front();
      q1.pop();
      if (relaxed[u])
        continue;
      relaxed[u] = 1;
      for (auto [v, w] : elist[u])
        if (dis[v] == -1 || dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          pre[v] = u;
          if (w)
            q2.push(v);
          else
            q1.push(v);
        }
    }
  }
  cout << dis[0] << endl;
  if (dis[0] == -1)
    return 0;
  vector<int> path;
  int cur = 0;
  while (cur != n) {
    cur = pre[cur];
    if (TH2 <= cur && cur <= (TH2 + n))
      path.push_back(cur - TH2);
  }
  reverse(all(path));
  for (int i : path)
    cout << i << ' ';
}