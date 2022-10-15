#include <bits/stdc++.h>

using namespace std;

int n, m, ka, kb;
vector<int> a, b;

signed main() {
///  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

 /// freopen ("___input___.txt", "r", stdin);

  cin >> n >> m >> ka >> kb;
  a.resize(ka);
  b.resize(kb);

  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;


  if (ka >= m || kb >= n) {
    cout << "No\n";
    exit(0);
  }

  while (ka < m - 1) {
    a.push_back(n);
    ka++;
  }

  while (kb < n - 1) {
    b.push_back(n + m);
    kb++;
  }
  map<int, int> fa, fb;

  for (auto &x : a) fa[x]++;
  for (auto &x : b) fb[x]++;

  assert((int) a.size() == m - 1);
  assert((int) b.size() == n - 1);

  vector<bool> vis(n + m + 1, false);

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  set<int> unseen_verts;
  for (int i = 1; i <= n + m; i++) {
    unseen_verts.insert(i);
  }

  for (auto &x : a) unseen_verts.erase(x);
  for (auto &x : b) unseen_verts.erase(x);

  vector<pair<int, int>> edges;

  vector<int> la, lb;

  while (!unseen_verts.empty()) {
    int v = *unseen_verts.begin();
    ///cout << "v = " << v << "\n";
    unseen_verts.erase(v);
    if (v <= n) {
      if (b.empty()) {
        break;
      }
      lb.push_back(b.back());
      assert(!b.empty());
      vis[v] = true;
      edges.push_back({b.back(), v});
      if (fb[b.back()] == 1) {
        unseen_verts.insert(b.back());
      }
      fb[b.back()]--;
      b.pop_back();
    } else {
      if (a.empty()) {
        break;
      }
      la.push_back(a.back());
      assert(!a.empty());
      vis[v] = true;
      edges.push_back({a.back(), v});
      if (fa[a.back()] == 1) {
        unseen_verts.insert(a.back());
      }
      fa[a.back()]--;
      a.pop_back();
    }
  }

  assert((int) edges.size() == n + m - 2);
  vector<int> unv;
  for (int i = 1; i <= n + m; i++) {
    if (!vis[i]) {
      unv.push_back(i);
    }
  }
  assert((int) unv.size() == 2);
  edges.push_back({unv[0], unv[1]});
  ///cout << n + m - 1 << " vs "  << (int) edges.size() << "\n";
  cout << "Yes\n";
  for (auto &it : edges) {
    cout << it.first << " " << it.second << "\n";
  }
}