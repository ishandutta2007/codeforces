#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
int n, m;
vector <pair <int, int>> g[N];
bool u[N];
int dep[N];
int mn_dep[N];
vector <pair <int, int>> lol;

void dfs(int nod) {
  mn_dep[nod] = dep[nod];
  u[nod] = 1;
  for (auto &it : g[nod]) {
    int nou = it.first;
    if (u[nou] == 0) {
      lol.push_back({nod, nou});
      dep[nou] = 1 + dep[nod];
      dfs(nou);
      mn_dep[nod] = min(mn_dep[nod], mn_dep[nou]);
    } else {
      if (dep[nou] < dep[nod] - 1) {
        mn_dep[nod] = min(mn_dep[nod], dep[nou]);
      }
    }
  }
}

map <pair <int, int>, bool> blocked;
vector <pair <int, bool>> g2[N];

int col[N], cur_col;
bool have[N];
void comps_dfs(int nod) {
  col[nod] = cur_col;
  for (auto &it : g[nod]) {
    int nou = it.first;
    if (blocked[{nod, nou}]) continue;
    if (it.second) {
      have[cur_col] = 1;
    }
    if (col[nou] == 0) {
      comps_dfs(nou);
    }
  }
}

vector <int> path;
map <pair <int, int>, bool> is;

void find_path(int cur, int want, int par, bool ok) {
  path.push_back(cur);
  if (cur == want) {
    for (auto &ctcs : path) {
      if (have[ctcs]) {
        ok = 1;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    exit(0);
  }
  for (auto &nou : g2[cur]) {
    if (nou.first == par) continue;
    find_path(nou.first, want, cur, (ok | nou.second));
  }
  path.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
    if (c == 1) {
      is[{a, b}] = is[{b, a}] = 1;
    }
  }

  dfs(1);

  for (auto &it : lol) {
    int a = it.first, b = it.second;
    if (mn_dep[b] > dep[a]) {
      blocked[{a, b}] = blocked[{b, a}] = 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (col[i] == 0) {
      cur_col++;
      comps_dfs(i);
    }
  }

  for (auto &it : blocked) {
    if (it.second) {
      int a = it.first.first, b = it.first.second;
      g2[col[a]].push_back({col[b], is[{a, b}]});
    }
  }

  int s, t;
  cin >> s >> t;
  int a = col[s], b = col[t];
  find_path(a, b, -1, 0);


  return 0;
}