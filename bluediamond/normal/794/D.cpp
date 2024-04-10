#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = (int) 3e5 + 7;
int n, m, root[N], sol[N];
vector<int> g[N];

void bad() {
  cout << "NO\n";
  exit(0);
}

bool cmp(int i, int j) {
  return g[i] < g[j];
}

void dfs(int a, int dir = 0) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (root[b] != b || b == a) continue;
    if (sol[b] && abs(sol[a] - sol[b]) > 1) bad();
    if (sol[b] == 0) kids.push_back(b);
  }
  if (dir && (int) kids.size() > 1) bad();
  if (!dir && (int) kids.size() > 2) bad();
  if (!dir) {
    dir = 1;
    for (auto &b : kids) {
      if (sol[b]) continue;
      sol[b] = sol[a] + dir;
      dfs(b, dir);
      dir *= -1;
    }
  } else {
    for (auto &b : kids) {
      if (sol[b]) continue;
      sol[b] = sol[a] + dir;
      dfs(b, dir);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 1; i <= n; i++) {
    g[i].push_back(i);
    sort(g[i].begin(), g[i].end());
  }

  vector<int> ord(n + 1); iota(ord.begin(), ord.end(), 0); sort(ord.begin(), ord.end(), cmp);


  /**
  daca exista solutie => exista solutie in care toate nodurile care au ac lista de adiacenta
  o sa fie cu ac valoare.
  de ce?
  presupunem ca avem nodul a si nodul b
  g[a] = g[b]
  v[a] = i
  v[b] = i + 1
  atunci toate valorile vecinilor trebuie sa fie (i, i+1) pentru ca daca as avea un i-1 sau i+2 atunci nu s-ar respecta pentru valoarea
  opusa.

  **/

  for (int i = 1; i <= n; i++) {
    ///cout << " = " << ord[i] << " " << (g[ord[i]] == g[ord[i - 1]]) << "\n";
    if (g[ord[i]] == g[ord[i - 1]]) {
      root[ord[i]] = root[ord[i - 1]];
    } else {
      root[ord[i]] = ord[i];
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!sol[i] && root[i] == i) {
      sol[i] = (int) 1e7;
      dfs(i);
      break;
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << sol[root[i]] << " ";
  }
  cout << "\n";

  return 0;
}