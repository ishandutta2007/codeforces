#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int UP    = 0;
const int RIGHT = 1;
const int DOWN  = 2;
const int LEFT  = 3;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, m, nn, b;
vector<vector<bool>> col;
vector<vector<int>> adj, rev;
vector<int> seen, past, group, sz;

int dfs(int u) {
  if (past[u]) {
    group[u] = u;
    ++sz[u];
    return u;
  }
  if (seen[u]) return 0;
  seen[u] = true;
  past[u] = true;
  int res = 0;
  for (auto& v : adj[u]) {
    int x = dfs(v);
    if (x && x != u) {
      group[u] = x;
      ++sz[x];
      res = x;
    }
  }
  past[u] = false;
  return res;
}

vector<pii> by_dist;

void rdfs(int u, int d, int gsz) {
  if (seen[u] == 2) {
    return;
  }
  by_dist[d%gsz].first++;
  int i = u/b, j = u%b;
  by_dist[d%gsz].second += !col[i][j];
  seen[u] = 2;
  for (auto& v : rev[u]) {
    rdfs(v, d+1, gsz);
  }
}

int mpof[256];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  mpof['U'] = UP;
  mpof['D'] = DOWN;
  mpof['L'] = LEFT;
  mpof['R'] = RIGHT;
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> n >> m;
    col = vector<vector<bool>>(n+2, vector<bool>(m+2));
    nn = (n+2)*(m+2);
    b = m+2;
    rev = adj = vector<vector<int>>(nn);
    sz = group = past = seen = vector<int>(nn);

    for (int i=1; i<=n; ++i) {
      string s;
      cin >> s;
      for (int j=1; j<=m; ++j) {
        col[i][j] = s[j-1]-'0';
      }
    }
    for (int i=1; i<=n; ++i) {
      string s;
      cin >> s;
      for (int j=1; j<=m; ++j) {
        int k = mpof[s[j-1]];
        adj[i*b+j].push_back((i+dr[k])*b + (j+dc[k]));
        rev[(i+dr[k])*b + (j+dc[k])].push_back(i*b+j);
      }
    }
    for (int i=1; i<=n; ++i) {
      for (int j=1; j<=m; ++j) {
        dfs(i*b+j);
      }
    }
    int ans1 = 0, ans2 = 0;
    for (int i=1; i<=n; ++i) {
      for (int j=1; j<=m; ++j) {
        if (group[i*b+j] == i*b+j) {
          by_dist.clear();
          by_dist.resize(sz[i*b+j]);
          rdfs(i*b+j, 0, sz[i*b+j]);
          for (auto& p : by_dist) {
            ans1 += p.first != 0;
            ans2 += p.second != 0;
          }
        }
      }
    }
    cout << ans1 << " " << ans2 << "\n";
  }
  return 0;
}