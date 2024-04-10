#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

const int N = 600 + 7;
bool home = 1;
int n;
bool act[N];
vector<int> gg[N];
map<vector<int>, int> memo;

int ask(vector<int> v) {
  sort(v.begin(), v.end());
  for (int i = 1; i < (int) v.size(); i++) {
    assert(v[i] != v[i - 1]);
  }
  if ((int) v.size() == 1) return 0;
  if (memo.count(v)) return memo[v];
  if (home) {
    for (auto &x : v) {
      act[x] = 1;
    }
    int ret = 0;
    for (auto &x : v) {
      for (auto &y : gg[x]) {
        if (x < y && act[y]) {
          ret++;
        }
      }
    }
    for (auto &x : v) {
      act[x] = 0;
    }
    memo[v] = ret;
    return ret;
  }
  cout << "? " << (int) v.size() << endl;
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
  int ret;
  cin >> ret;
  memo[v] = ret;
  return ret;
}

void add(int x, int y) {
  gg[x].push_back(y);
  gg[y].push_back(x);
}

vector<int> operator + (vector<int> a, vector<int> b) {
  for (auto &x : b) {
    a.push_back(x);
  }
  return a;
}

bool is_inside[N];

bool este(vector<int> a, vector<int> b) {
  if (a.empty() || b.empty()) return 0;
/**
  for (auto &x : a) {
    cout << x << " ";
  }
  cout << " --- ";
  for (auto &x : b) {
    cout << x << " ";
  }
  cout << "\n";
**/
  return ask(a + b) - ask(a) - ask(b) > 0;
}

int col[N];
vector<int> g[N];
bool good = 1;

void dfs(int a) {
  for (auto &b : g[a]) {
    if (col[b] == 0) {
      col[b] = 3 - col[a];
      dfs(b);
    } else {
      good &= (col[a] + col[b] == 3);
    }
  }
}

mt19937 rng((long long) (new char));

pair<vector<int>, vector<int>> part(vector<int> a) {
  vector<int> f, s;
  for (int i = 0; i < (int) a.size(); i++) {
    if (rng() & 1) f.push_back(a[i]);
    else s.push_back(a[i]);
  }
  return {f, s};
}

int p[N];

void defese(int a) {
  for (auto &b : g[a]) {
    if (p[b] == -1) {
      p[b] = a;
      defese(b);
    }
  }
}

signed main() {
/**
#ifdef ONLINE_JUDGE
  home = 0;
#endif**/
  home = 0;
  if (home) {
    if (1) {
      n = 3;
      add(1, 2);
      add(2, 3);
      add(1, 3);
    } else {
      n = 4;
      add(4, 1);
      add(1, 3);
      add(3, 2);
      add(2, 4);
    }
  } else {
    cin >> n;
    if (n == 1) {
      cout << "Y 1" << endl;
      cout << 1 << endl;
      return 0;
    }
  }
  vector<int> inside = {1};
  vector<pair<int, int>> edges;
  is_inside[1] = 1;
  while ((int) inside.size() < n) {
    /// extend
    vector<int> outside;
    for (int i = 1; i <= n; i++) {
      if (!is_inside[i]) {
        outside.push_back(i);
      }
    }
    vector<int> x = inside, y = outside;
    while ((int) x.size() > 1) {
      vector<int> f, s;
      for (int j = 0; j < (int) x.size() / 2; j++) f.push_back(x[j]);
      for (int j = (int) x.size() / 2; j < (int) x.size(); j++) s.push_back(x[j]);
      if (este(f, y)) {
        x = f;
      } else {
        if (home) {
          assert(este(s, y));
        }
        x = s;
      }
    }
    swap(x, y);
    if (home) {
      assert(este(x, y));
    }
    while ((int) x.size() > 1) {
      vector<int> f, s;
      for (int j = 0; j < (int) x.size() / 2; j++) f.push_back(x[j]);
      for (int j = (int) x.size() / 2; j < (int) x.size(); j++) s.push_back(x[j]);
      if (este(f, y)) {
        x = f;
      } else {
        if (home) {
          assert(este(s, y));
        }
        x = s;
      }
    }
    swap(x, y);
    assert((int) x.size() == 1);
    assert((int) y.size() == 1);
    edges.push_back({x[0], y[0]});
    is_inside[y[0]] = 1;
    inside.push_back(y[0]);
  }
  for (auto &it : edges) {
    g[it.first].push_back(it.second);
    g[it.second].push_back(it.first);
    ///cout << ": " << it.first << " " << it.second << "\n";
  }
  col[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    assert(col[i] == 1 || col[i] == 2);
  }
  assert(good);
  vector<int> f, s;
  for (int i = 1; i <= n; i++) {
    if (col[i] == 1) f.push_back(i);
    else s.push_back(i);
  }
  good &= (ask(f) == 0);
  good &= (ask(s) == 0);
  if (good) {
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
      if (col[i] == 1) ret.push_back(i);
    }
    cout << "Y " << (int) ret.size() << endl;
    for (auto &i : ret) {
      cout << i << " ";
    }
    cout << endl;
    return 0;
  }
  if (!ask(f)) {
    f = s;
  }
  vector<int> x, y;
  while (1) {
    auto pr = part(f);
    if (este(pr.first, pr.second)) {
      x = pr.first;
      y = pr.second;
      break;
    }
  }
  while ((int) x.size() > 1) {
    vector<int> f, s;
    for (int j = 0; j < (int) x.size() / 2; j++) f.push_back(x[j]);
    for (int j = (int) x.size() / 2; j < (int) x.size(); j++) s.push_back(x[j]);
    if (este(f, y)) {
      x = f;
    } else {
      if (home) {
        assert(este(s, y));
      }
      x = s;
    }
  }
  swap(x, y);
  if (home) {
    assert(este(x, y));
  }
  while ((int) x.size() > 1) {
    vector<int> f, s;
    for (int j = 0; j < (int) x.size() / 2; j++) f.push_back(x[j]);
    for (int j = (int) x.size() / 2; j < (int) x.size(); j++) s.push_back(x[j]);
    if (este(f, y)) {
      x = f;
    } else {
      if (home) {
        assert(este(s, y));
      }
      x = s;
    }
  }
  for (int i = 1; i <= n; i++) p[i] = -1;
  swap(x, y);
  assert((int) x.size() == 1);
  assert((int) y.size() == 1);
  defese(x[0]);
  vector<int> cur;
  while (y[0] != x[0]) {
    cur.push_back(y[0]);
    y[0] = p[y[0]];
  }
  cur.push_back(x[0]);
  cout << "N " << (int) cur.size() << endl;
  for (auto &x : cur) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}