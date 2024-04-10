#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 300300;
int a[N], b[N], h[N];
int preorder[N], postorder[N];
vector<int> po;

vector<int> adj[N];
int par[N];
int n;

int zz, yy;
void dfs(int u, int d) {
  po.push_back(u);
  preorder[u] = ++zz;
  h[u] = d;
  for (auto& v : adj[u]) {
    dfs(v, d+1);
  }
  postorder[u] = ++yy;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<=n-1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    par[v] = u;
  }
  vector<int> below;
  for (int i=2; i<=n; ++i) {
    if (a[par[i]] > a[i]) {
      below.push_back(i);
    }
  }
  for (int i=1; i<=n; ++i) {
    sort(adj[i].begin(), adj[i].end(), [](const int& x, const int& y) {
      return a[x] < a[y];
    });
  }
  dfs(1, 1);
  if (below.empty()) {
    for (int i=1; i<=n; ++i) {
      if (preorder[i] != a[i]) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n0\n";
    for (int i=1; i<=n; ++i) {
      cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
  }
  sort(below.begin(), below.end(), [](const int& i, const int& j) {
    return a[i] < a[j];
  });
  if (a[below[0]] != 1 || a[below.back()] != below.size()) {
    cout << "NO\n";
    return 0;
  }
  int w = below.back();
  ll ans = 0;
  while (w != 1) {
    swap(a[w], a[par[w]]);
    w = par[w];
    ++ans;
  }
  below.pop_back();
  for (int i=1; i<=n; ++i) {
    if (postorder[i] <= below.size()) {
      b[i] = postorder[i];
    }
  }
  int qq = below.size();
  for (auto& u : po) {
    if (b[u]) continue;
    b[u] = ++qq;
  }
  for (int i=1; i<=n; ++i) {
    if (a[i] != b[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i=1; i<=n; ++i) {
    if (a[i] <= below.size()) {
      ans += h[i]-1;
    }
  }
  cout << "YES\n" << ans << "\n";
  for (int i=1; i<=n; ++i) {
    cout << preorder[i] << " ";
  }
  cout << "\n";
  return 0;
}