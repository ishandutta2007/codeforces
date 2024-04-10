#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 5e5 + 7;
const int K = 20;
int n;
int par[N];
int level[N];
int l[N];
int r[N];
int who[N];
int top;
int eulerTour[2 * N];
int lg[2 * N];
int topEuler;
int first[N];
int last[N];
pair<int, int> rmq[K][2 * N];
ll res[N];
vector<int> g[N];

void dfs(int a) {
  eulerTour[++topEuler] = a;
  first[a] = last[a] = topEuler;
  l[a] = ++top;
  who[top] = a;
  for (auto &b : g[a]) {
    level[b] = 1 + level[a];
    dfs(b);
    eulerTour[++topEuler] = a;
    last[a] = topEuler;
  }
  r[a] = top;
}

int lca(int a, int b) {
  if (first[a] > last[b]) {
    swap(a, b);
  }
  a = first[a];
  b = last[b];
  int y = lg[b - a + 1];
  return min(rmq[y][a], rmq[y][b - (1 << y) + 1]).second;
}

bool cmp(int a, int b) {
  return l[a] < l[b];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n;
  int root = 0;
  for (int i = 1; i <= n; i++) {
    cin >> par[i];
    if (par[i] == 0) {
      root = i;
    }
    g[par[i]].push_back(i);
  }
  assert(root);
  level[root] = 1;
  dfs(root);
  for (int i = 1; i <= topEuler; i++) {
    rmq[0][i] = {level[eulerTour[i]], eulerTour[i]};
    if (i >= 2) {
      lg[i] = 1 + lg[i / 2];
    }
  }
  for (int k = 1; (1 << k) <= topEuler; k++) {
    for (int i = 1; i + (1 << k) - 1 <= topEuler; i++) {
      rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
    }
  }



  vector<pair<int, int>> lol;
  for (int i = 1; i <= n; i++) {
    lol.push_back({level[i], i});
  }
  sort(lol.begin(), lol.end());

  int l = 0;
  while (l < (int) lol.size()) {
    int r = l;
    while (r + 1 < (int) lol.size() && lol[r + 1].first == lol[r].first) {
      r++;
    }
    vector<int> nodes;
    for (int i = l; i <= r; i++) {
      nodes.push_back(lol[i].second);
      res[lol[i].second] = res[par[lol[i].second]] + level[lol[i].second] - 1;

    }

    sort(nodes.begin(), nodes.end(), cmp);
    for (int it = 0; it < 2; it++) {
      ll zu = 0;
      vector<pair<int, int>> kek;
      for (int i = 1; i < (int) nodes.size(); i++) {
        int node = nodes[i];
        int lc = lca(nodes[i], nodes[i - 1]), aici = 1;
        while (!kek.empty() && level[lc] < level[kek.back().first]) {
          zu -= level[kek.back().first] * kek.back().second;
          aici += kek.back().second;
          kek.pop_back();
        }

        kek.push_back({lc, aici});
        zu += level[kek.back().first] * kek.back().second;
        res[node] += zu;
      }
      reverse(nodes.begin(), nodes.end());
    }
    l = r + 1;
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}