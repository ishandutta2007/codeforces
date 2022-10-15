#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, m, dmin[N], vecgood[N], cntt[N];
vector<int> g[N], inv[N];
int cnt;
vector<int> path;
bool uniq[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    inv[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    dmin[i] = -1;
  }
  cin >> cnt;
  path.resize(cnt);
  for (int i = 0; i < cnt; i++) {
    cin >> path[i];
  }
  dmin[path.back()] = 0;
  queue<int> q;
  q.push(path.back());
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto &b : inv[a]) {
      if (dmin[b] == -1) {
        dmin[b] = 1 + dmin[a];
        q.push(b);
      }
      cntt[b] += (dmin[b] == 1 + dmin[a]);
    }
  }
  for (int i = 1; i <= n; i++) {
    uniq[i] = (cntt[i] == 1);
  }
  int s1 = 0, s2 = 0;
  for (int i = 0; i + 1 < cnt; i++) {
    s1 += (dmin[path[i + 1]] != dmin[path[i]] - 1);
    if (dmin[path[i + 1]] == dmin[path[i]] - 1) {
      if (!uniq[path[i]]) {
        s2++;
      }
    }
  }
  cout << s1 << " " << s2 + s1 << "\n";
}