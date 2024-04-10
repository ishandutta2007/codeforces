#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 0;
typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));

const int N = 100 + 7;
int n, edge[N][N];

int ask1(int a, int b) {
  assert(a != b);
  cout << "1 " << a - 1 << " " << b - 1 << endl;
  int x;
  if (home) {
    x = edge[a][b];
  } else {
    cin >> x;
    assert(x != -1);
  }
  return x;
}

int ask2(int a, vector<int> b) {
  if (b.empty()) {
    return 0;
  }
  cout << "2 " << a - 1 << " " << (int) b.size() << " ";
  for (auto &x : b) {
    cout << x - 1 << " ";
  }
  cout << endl;
  int x;
  if (home) {
    x = 0;
    for (auto &no : b) {
      x |= edge[a][no];
    }
  } else {
    cin >> x;
    assert(x != -1);
  }
  return x;
}


vector<int> rec(int l, int r) {
  if (l > r) {
    return {};
  }
  if (l == r) {
    return {l};
  }
  int m = (l + r) / 2;
  auto a = rec(l, m);
  auto b = rec(m + 1, r);
  vector<int> c;
  int pa = 0, pb = 0, sa = (int) a.size(), sb = (int) b.size();
  while (pa < sa && pb < sb) {
    if (ask1(a[pa], b[pb])) {
      c.push_back(a[pa++]);
    } else {
      c.push_back(b[pb++]);
    }
  }
  while (pa < sa) {
    c.push_back(a[pa++]);
  }
  while (pb < sb) {
    c.push_back(b[pb++]);
  }
  return c;
}

int t[N];

int root(int a) {
  if (t[a] == a) {
    return a;
  } else {
    return t[a] = root(t[a]);
  }
}

void unite(int a, int b) {
  t[root(a)] = root(b);
}

bool pot[N][N], senpai[N];

signed main() {
  if (home) {
    ifstream fin("tony_stark");
    fin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) edge[i][j] = -1;
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
      int x, y;
      fin >> x >> y;
      x++;
      y++;
      edge[x][y] = 1;
      edge[y][x] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          assert(edge[i][j] == 0 || edge[i][j] == 1);
        }
      }
    }
  }
  int tt;
  if (home) tt = 1; else
  cin >> tt;
  while (tt--) {
    if (!home) cin >> n;
    auto ord = rec(1, n);
    for (int i = 1; i <= n; i++) {
      t[i] = i;
    }
    vector<int> nodes = ord;
    for (int i = n - 1; i >= 0; i--) {
      while ((int) nodes.size() > i) {
        nodes.pop_back();
      }
      int last = -1;
      while (ask2(ord[i], nodes)) {
        nodes.pop_back();
        last = (int) nodes.size();
      }
      if (last != -1) {
        for (int j = last + 1; j <= i; j++) {
          unite(ord[j - 1], ord[j]);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      senpai[i] = 1;
    }
    int l = 0;
    while (l < n) {
      int r = l;
      while (r + 1 < n && root(ord[r]) == root(ord[r + 1])) {
        r++;
      }
      for (int i = l; i <= r; i++) {
        for (int j = 1; j <= n; j++) {
          pot[ord[i]][j] = senpai[j];
        }
      }
      for (int i = l; i <= r; i++) {
        senpai[ord[i]] = 0;
      }
      l = r + 1;
    }
    cout << 3 << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << pot[i][j];
        pot[i][j] = 0;
      }
      cout << endl;
    }
    int heg;
    cin >> heg;
  }
  return 0;
}