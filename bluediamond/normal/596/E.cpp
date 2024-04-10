#include <bits/stdc++.h>

using namespace std;

bool home = 1;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int Nm = 200 + 7;
const int N = Nm * Nm;
int n, m, q, mat[Nm][Nm], xd[10], yd[10], a[N];
bool vis[N];
bool ever[N];
int spre[N];
bool intra[N];

int get_id(int i, int j) {
  return m * (i - 1) + j;
}

int f[10];

signed realMain() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) mat[i][j] = s[j - 1];
  }
  for (int i = 0; i < 10; i++) cin >> xd[i] >> yd[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[get_id(i, j)] = mat[i][j];
      int i2 = i + xd[mat[i][j] - '0'];
      int j2 = j + yd[mat[i][j] - '0'];
      if (1 <= i2 && i2 <= n && 1 <= j2 && j2 <= m) {

        spre[get_id(i, j)] = get_id(i2, j2);
      } else {
        spre[get_id(i, j)] = -1;
      }
    }
  }
  n *= m;
  for (int i = 1; i <= n; i++) {
    if (spre[i] != -1) intra[spre[i]] = 1;
  }
  vector<pair<string, set<char>>> v;
  for (int i = 1; i <= n; i++) {
    if (intra[i] == 0) {
      vector<int> path;
      int finito = 0;
      int j = i;
      while (!vis[j]) {
        path.push_back(j);
        vis[j] = 1;
        if (spre[j] == -1) {
          finito = 1;
          break;
        }
        j = spre[j];
      }
      if (finito) {
        string s;
        for (auto &k : path) s += a[k];
        set<char> t;
        t.insert(s.back());
        v.push_back({s, t});
      } else {
        string s;
        set<char> t;
        bool is = 0;
        for (auto &k : path) {
          is |= (k == j);
          if (!is) s += a[k];
          else t.insert(a[k]);
        }
        v.push_back({s, t});
      }
      ///cout << " => " << finito << "\n";
      for (auto &j : path) vis[j] = 0, ever[j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!ever[i]) {
      if (!intra[i]) {
        assert(0);
      }
     /// cout << " = " << i << " -> " << spre[i] << "\n";
      set<char> s;
      int j = i;
      while (!ever[j]) {
        ever[j] = 1;
        s.insert(a[j]);
        assert(spre[j] != -1);
        j = spre[j];
      }
      v.push_back({"", s});
    }
  }
  int idx = 0;
  while (q--) {
    idx++;
    string s;
    cin >> s;
    int p = 0;
    bool ok = 0;
    for (int j = 0; j < 10; j++) f[j] = 0;
    for (auto &x : s) f[x - '0']++;
    for (auto &it : v) {
      string bef = it.first;
      set<char> cy = it.second;
      p = 0;
      for (auto &ch : bef) {
        if (p < (int) s.size() && ch == s[p]) {
          f[s[p] - '0']--;
          p++;
        }
      }
      ok = 1;
      for (int j = 0; j < 10; j++) {
        if (f[j] && !cy.count(j + '0')) ok = 0;
      }
      for (int j = 0; j < p; j++) f[s[j] - '0']++;
      if (ok) {
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}