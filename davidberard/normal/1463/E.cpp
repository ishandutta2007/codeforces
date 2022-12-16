#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 300300;
int n, k, r;
int par[N];
int up[N], down[N], head[N];
int sz[N];
int in[N];
bool is_taken[N];
queue<int> q;
int marker[N];
vector<int> adj[N], ch[N];

bool upp(int u, int r) {
  if (marker[u] == r) {
    return false;
  }
  if (head[u]) {
    return true;
  }
  marker[u] = r;
  if (up[u]) {
    bool res = upp(up[u], r);
    if (!res) {
      return false;
    }
    head[u] = head[up[u]];
    sz[head[u]]++;
  } else {
    head[u] = u;
    sz[head[u]]++;
  }
  return true;
}

vector<int> ans;
void take(int x) {
  do {
    ans.push_back(x);
    x = down[x];
  } while (x);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i=1; i<=n; ++i) {
    cin >> par[i];
    if (!par[i]) {
      r = i;
    }
    ch[par[i]].push_back(i);
  }
  for (int i=1; i<=k; ++i) {
    int x, y;
    cin >> x >> y;
    if (down[x] || up[y]) {
      cout << "0\n";
      return 0;
    }
    down[x] = y;
    up[y] = x;
  }
  for (int i=1; i<=n; ++i) {
    if (!upp(i, i)) {
      cout << 0 << "\n";
      return 0;
    }
  }
  for (int i=1; i<=n; ++i) {
    if (par[i] && head[par[i]] != head[i]) {
      adj[head[par[i]]].push_back(head[i]);
      in[head[i]]++;
    }
  }
  if (in[head[r]] == 0) {
    q.push(head[r]);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    assert(head[u] == u);
    take(u);
    for (auto& v : adj[u]) {
      if (--in[v] == 0) {
        q.push(v);
      }
    }
  }
  if (ans.size() < n) {
    cout << 0 << endl;
    return 0;
  }
  for (auto& x : ans) {
    if (par[x] && !is_taken[par[x]]) {
      cout << 0 << endl;
      return 0;
    }
    is_taken[x] = 1;
  }
  for (auto& x : ans) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}