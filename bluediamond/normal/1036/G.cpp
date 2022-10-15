#include <bits/stdc++.h>


using namespace std;

bool home = 1;

const int N = 20;
const int NNN = (int) 1e6 + 7;
int n, m;
vector < int > g[NNN], sources, sinks;
bool is_source[NNN];
bool is_sink[NNN];
bool reachvert[NNN];
bool reach[N][N];
bool can[2 * N][2 * N];

void dfs(int vertex) {
  reachvert[vertex] = 1;
  for (auto & b: g[vertex]) dfs(b);
}

int cntbits(int x) {
  int s = 0;
  while (x) {
    s++;
    x -= x & (-x);
  }
  return s;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  cin >> n >> m;
  for (int i = 1; i <= n; i++) is_source[i] = is_sink[i] = 1;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    is_source[y] = 0;
    is_sink[x] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (is_source[i]) sources.push_back(i);
    if (is_sink[i]) sinks.push_back(i);
  }
  int ninit = n;
  n = (int) sources.size();
  assert((int) sources.size() == n);
  assert((int) sinks.size() == n);
  assert(n <= 20);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= ninit; j++) reachvert[j] = 0;
    dfs(sources[i]);
    for (int j = 0; j < n; j++) reach[i][j] = reachvert[sinks[j]];
  }
  vector < int > sg(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (reach[i][j]) sg[i] += (1 << j);
    }
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    int rch = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) rch |= sg[i];
    }
    if (cntbits(rch) < cntbits(mask)) {
      cout << "NO\n";
      exit(0);
    }
    if (cntbits(mask) < n && cntbits(rch) <= cntbits(mask)) {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n";
}