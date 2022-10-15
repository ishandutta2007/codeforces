#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
int m;
int dep[N];
int nodes[N];
int par[N];
bool on[N];
bool vis[N];
pair<int, int> contain[N];
vector<int> g[N];

void print(vector<int> a) {
  cout << (int) a.size() << " ";
  for (auto &x : a) {
    cout << x << " ";
  }
  cout << "\n";
}

void dfs(int a, int p, int level) {
  par[a] = p;
  vis[a] = 1;
  dep[a] = level;
  nodes[level] = a;
  for (auto &b : g[a]) {
    if (vis[b] == 0) {
      dfs(b, a, level + 1);
      continue;
    }
    for (int d = dep[b] + 1; d < dep[a]; d++) {
      int c = nodes[d];
      if (contain[c] == make_pair(-1, -1)) {
        contain[c] = {a, b};
        continue;
      }
      pair<int, int> it = contain[c];
      vector<int> cycle1, cycle2;
      int node = a;
      while (node != b) {
        cycle1.push_back(node);
        node = par[node];
      }
      cycle1.push_back(b);
      node = it.first;
      while (node != it.second) {
        cycle2.push_back(node);
        node = par[node];
      }
      cycle2.push_back(it.second);
      for (auto &x : cycle1) {
        on[x] = 1;
      }
      int first = -1, last = -1;
      for (auto &x : cycle2) {
        if (on[x]) {
          last = x;
          if (first == -1) {
            first = x;
          }
        }
      }
      int p_first = 0, p_last = 0;
      while (cycle2[p_first] != first) {
        p_first++;
      }
      while (cycle2[p_last] != last) {
        p_last++;
      }
      vector<int> x, y, z;
      for (int i = p_first; i <= p_last; i++) {
        x.push_back(cycle2[i]);
      }
      for (int i = p_last; i < (int) cycle2.size(); i++) {
        y.push_back(cycle2[i]);
      }
      for (int i = 0; i <= p_first; i++) {
        y.push_back(cycle2[i]);
      }
      reverse(y.begin(), y.end());
      p_first = 0;
      p_last = 0;
      while (cycle1[p_first] != first) {
        p_first++;
      }
      while (cycle1[p_last] != last) {
        p_last++;
      }
      for (int i = p_last; i < (int) cycle1.size(); i++) {
        z.push_back(cycle1[i]);
      }
      for (int i = 0; i <= p_first; i++) {
        z.push_back(cycle1[i]);
      }
      reverse(z.begin(), z.end());
      cout << "YES\n";
      print(x);
      print(y);
      print(z);
      exit(0);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen ("input", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    contain[i] = make_pair(-1, -1);
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      dfs(i, -1, 1);
    }
  }
  cout << "NO\n";
}