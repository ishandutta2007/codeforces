#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 2e5 + 7;
int n, m, total, t[N];
set<int> g[N];

struct edge {
  int a, b, c;
} e[N];

bool operator < (edge a, edge b) {
  return a.c < b.c;
}

int root(int a) {
  if (t[a] == a) return a;
  return t[a] = root(t[a]);
}

void unite(int a, int b) {
  t[root(a)] = root(b);
}

mt19937 rng((long long) (new char));

vector<int> ord;
set<int> s;

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    t[i] = i;
    g[i] = {i};
  }
  vector<edge> edges(m);
  for (auto &it : edges) {
    cin >> it.a >> it.b >> it.c;
    g[it.a].insert(it.b);
    g[it.b].insert(it.a);
    if (it.a > it.b) {
      swap(it.a, it.b);
    }
    total ^= it.c;
  }
  if (!home && n <= 1000) {
    /// fie folosesc doar 0-uri, fie intru in cazul specific
    vector<vector<int>> vals(n + 1, vector<int> (n + 1, 0));
    for (auto &it : edges) {
      vals[it.a][it.b] = it.c;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (!vals[i][j]) {
          edges.push_back({i, j, 0});
        }
      }
    }
    sort(edges.begin(), edges.end());
    vector<edge> luate;
    int zero = 0;
    ll ret = 0;
    for (auto &it : edges) {
      if (root(it.a) != root(it.b)) {
        unite(it.a, it.b);
        ret += it.c;
        luate.push_back(it);
        zero += (it.c == 0);
      }
    }
    if (m + zero == n * (n - 1) / 2) {
      ll bef = ret;
      ret += total;
      for (int i = 1; i <= n; i++) {
        t[i] = i;
      }
      for (auto &it : luate) {
        if (it.c > 0) {
          unite(it.a, it.b);
        }
      }
      /// acum efectiv simulez ce alta muchie ar fi putut sa fie aleasa
      for (auto &it : edges) {
        if (it.c > 0 && root(it.a) != root(it.b)) {
          ret = min(ret, bef + it.c);
        }
      }

    }
    cout << ret << "\n";

    return 0;
  }
  ll ret = 0;
  /// in cazul n e suficient de mare sa folosesc doar 0-uri
  ord.resize(n);
  iota(ord.begin(), ord.end(), 1);
  shuffle(ord.begin(), ord.end(), rng);
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  while (!s.empty()) {
    int i = ord[*s.begin()];
    s.erase(s.begin());
    ///dfs(i);
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      auto it = s.begin();
      while (it != s.end()) {
        int b = ord[*it];
        if (g[a].count(b)) {
          it++;
        } else {
          unite(a, b);
          q.push(b);
          it = s.erase(it);
        }
      }

    }
  }
  sort(edges.begin(), edges.end());
  for (auto &it : edges) {
    if (root(it.a) != root(it.b)) {
      unite(it.a, it.b);
      ret += it.c;
    }
  }
  cout << ret << "\n";
  return 0;
}