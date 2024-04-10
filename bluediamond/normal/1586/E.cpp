#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int relu(int x) {return max(x, 0);}

const int N = (int) 3e5 + 7;
int n, m, q, par[N];
vector<int> g[N];

void dfs(int a, int p = -1) {
  par[a] = p;
  for (auto &b : g[a]) {
    if (!par[b]) {
      dfs(b, a);
    }
  }
}

vector<int> get(int a) {
  vector<int> sol;
  while (a) {
    sol.push_back(a);
    a = par[a];
  }
  reverse(sol.begin(), sol.end());
  return sol;
}

int cnt[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!par[i]) {
      dfs(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    par[i] = relu(par[i]);
  }
  cin >> q;
  vector<pair<int, int>> cox(q);
  for (auto &it : cox) {
    cin >> it.first >> it.second;
    cnt[it.first]++;
    cnt[it.second]++;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] & 1) {
      int odds = 0;
      for (int i = 1; i <= n; i++) {
        odds += cnt[i] % 2;
      }
      cout << "NO\n";
      cout << odds / 2 << "\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (auto &it : cox) {
    int a = it.first, b = it.second;
    vector<int> ga = get(a), gb = get(b);
    int pz = 0;
    while (pz < (int) ga.size() && pz < (int) gb.size() && ga[pz] == gb[pz]) pz++;
    assert(gb.back() == b);
    assert(ga.back() == a);
    vector<int> sol;
    for (int i = (int) ga.size() - 1; i >= pz; i--) {
      sol.push_back(ga[i]);
    }
    sol.push_back(ga[pz - 1]);
    for (int i = pz; i < (int) gb.size(); i++) {
      sol.push_back(gb[i]);
    }
    cout << (int) sol.size() << "\n";
    if (sol[0] != a) {
      cout << "aa:" << pz << "and" << (int) ga.size() << "\n";
      return 0;
    }
    assert(sol[0] == a);
    if (sol.back() != b) {
      cout << "bb:" << pz << "and" << (int) gb.size() << "\n";
      return 0;
    }

    assert(sol.back() == b);
    for (auto &i : sol) {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}