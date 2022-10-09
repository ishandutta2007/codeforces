#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define len(x) ((int)x.size())

#define maxn 301010
int n, m;
vector<ii> gr[maxn];
int root = -1;
int d[maxn];

int p[maxn];
int findp(int u) { return p[u] = p[u] == u ? u : findp(p[u]); }
void join(int u, int v) {
  if (rand() & 1) swap(u, v);
  p[findp(u)] = findp(v);
}

vector<int> ans;
int cnt[maxn];
void dfs(int u, int p) {
  cnt[u] = d[u];
  for (auto i: gr[u]) {
    int v = i.xx;
    if (v == p) continue;
    dfs(v, u);
    if (cnt[v] & 1) ans.push_back(i.yy);
    cnt[u] = abs(cnt[u] - cnt[v]);
  }
}

int main() {
  srand(time(0));
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  int c1 = 0;
  rep1(i, n) {
    cin >> d[i];
    if (d[i] == -1) {
      root = i;
      d[i] = 0;
    }
    if (d[i] == 1) ++c1;
    p[i] = i;
  }

  if (root == -1 and (c1 & 1)) {
    cout << -1;
    return 0;
  }

  if (root == -1) root = 1;

  rep1(i, m) {
    int u, v; cin >> u >> v;
    if (findp(u) == findp(v)) continue;
    gr[u].push_back({v, i});
    gr[v].push_back({u, i});
    join(u, v);
  }

  dfs(root, root);

  cout << len(ans) << '\n';
  for (auto i: ans) cout << i << '\n';

  return 0;
}