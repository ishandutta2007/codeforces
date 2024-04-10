#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const int C = 2;
int mods[C];


void custom(bool ok) {
  if (!ok) {
    exit(0);
  }
}

class T {
public:
  int a[C];
  T() {
    for (int i = 0; i < C; i++) {
      a[i] = 0;
    }
  }
  T(int x) {
    for (int i = 0; i < C; i++) {
      a[i] = x;
      assert(x < mods[i]);
    }
  }
};

const int P = (int) 1e9 + 7;
const int A = 97;
const int B = 37;

bool operator < (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    if (ff.a[i] != ss.a[i]) return ff.a[i] < ss.a[i];
  }
  return (1 < 1);
}

bool operator == (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    if (ff.a[i] != ss.a[i]) return 0;
  }
  return 1;
}

T operator + (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    ff.a[i] += ss.a[i];
    if (ff.a[i] >= mods[i]) ff.a[i] -= mods[i];
  }
  return ff;
}

T operator - (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    ff.a[i] -= ss.a[i];
    if (ff.a[i] < 0) ff.a[i] += mods[i];
  }
  return ff;
}

T operator * (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    ff.a[i] = (ll) ff.a[i] * ss.a[i] % mods[i];
  }
  return ff;
}

mt19937 rng((long long) (new char));

bool isprime(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

T put[100000], aa, bb;
vector<int> g[100000];
int n;
bool vis[100000];
int sub[100000];



T dp[100000];


int pr[100000];

void calc(int a, int p = -1) {
  vector<pair<T, int>> cox;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;
    sub[a] += sub[b];
    cox.push_back({dp[b], b});
  }
  sort(cox.begin(), cox.end());

  int pt = 0;
  T cur(0);
  cur = cur + put[pt] * aa;
  pt++;
  for (auto &it : cox) {
    cur = cur + put[pt] * it.first;
    pt += 2 * sub[it.second];
  }
  cur = cur + put[pt] * bb;
  dp[a] = cur;
}

void dfs(int a, int p = -1) {
  //vis[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
  }
  calc(a, p);
}

vector<int> nodes;


void place(int a) {
  pr[a] = -1;
  nodes.push_back(a);
  sub[a] = 1;
  vis[a] = 1;
  for (auto &b : g[a]) {
    if (vis[b] == 0) {
      place(b);
      pr[b] = a;
      sub[a] += sub[b];
    }
  }
}


vector<pair<T, T>> get(vector<pair<int, int>> edges) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = 0;
  }
  for (auto &it : edges) {
    assert(1 <= it.first && it.first <= n);
    assert(1 <= it.second && it.second <= n);
    g[it.first].push_back(it.second);
    g[it.second].push_back(it.first);
  }
  vector<pair<T, T>> all;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      nodes.clear();
      place(i);
      vector<int> cens;
      int total = sub[i];
      for (auto &j : nodes) {
        int mx = total - sub[j];
        for (auto &it : g[j]) {
          if (it == pr[j]) continue;
          mx = max(mx, sub[it]);
        }
        if (mx <= total / 2) cens.push_back(j);
      }
      if ((int) cens.size() >= 3) {
        cout << "what : " << (int) cens.size() << "\n";
        /**for (auto &it : nodes) {
          for (auto &j : g[it]) {
            if (j < it) {
              cout << j << " " << it << "\n";
            }
          }
        }
        cout << "\n";**/
    /**    for (auto &it : cens) {
          cout << it << " ";
        }
        cout << "\n";**/
        for (auto &it : nodes) {
          cout << it << " : " << sub[it] << "\n";
        }
      }
      custom((int) cens.size() == 1 || (int) cens.size() == 2);
      if ((int) cens.size() == 1) cens.push_back(cens[0]);
      pair<T, T> kek;
      dfs(cens[0]);
      kek.first = dp[cens[0]];
      dfs(cens[1]);
      kek.second = dp[cens[1]];
      if (kek.second < kek.first) swap(kek.first, kek.second);
      all.push_back(kek);
    }
  }
  sort(all.begin(), all.end());
  return all;
}

bool home = 1;

const int N = 100 + 7;
int k;

void print(vector<T> v) {
  cout << " ---> ";
  for (auto &x : v) {
    //cout << "(" << x.a[0] << " " << x.a[1] << ") ";
    cout << x.a[0] << " ";
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  {
    for (int it = 0; it < C; it++) {
      while (1) {
        int x = (int) 1e9 + 100 + rng() % 10000;
        if (!isprime(x)) continue;
        mods[it] = x;
        break;
      }
    }


    put[0] = 1;
    put[1] = P;
    for (int i = 2; i < 100000; i++) {
      put[i] = put[1] * put[i - 1];
    }

    aa = A;
    bb = B;
  }

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    if (n == 2) {
      int m1, m2;
      cin >> m1;
      for (int i = 1; i <= m1; i++) {
        int x;
        cin >> x;
      }
      cin >> m2;
      for (int i = 1; i <= m2; i++) {
        int x;
        cin >> x;
      }
      if (m1 == 0 && m2 == 0) {
        cout << "YES\n";
        cout << "1 2\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    assert(k == n);
    vector<vector<pair<int, int>>> graphs;
    for (int i = 1; i <= n; i++) {
      int m;
      cin >> m;
      vector<pair<int, int>> graph(m);
      for (auto &it : graph) {
        cin >> it.first >> it.second;
      }
      graphs.push_back(graph);
    }

    int someleaf = -1;
    for (int i = 0; i < n; i++) {
      if ((int) graphs[i].size() == n - 2) {
        someleaf = i;
      }
    }
    if (someleaf == -1) {
      cout << "NO\n";
      continue;
    }
    ///cout << "YES\n";
    auto graph = graphs[someleaf];
    set<int> sverts;
    for (auto &it : graph) {
      sverts.insert(it.first);
      sverts.insert(it.second);
    }
    assert((int) sverts.size() == n - 1);
    int other = n * (n + 1) / 2;
    for (auto &x : sverts) {
      other -= x;
    }
    vector<int> verts;
    for (auto &v : sverts) {
      verts.push_back(v);
    }
    bool ok = 0;
    vector<vector<pair<T, T>>> need;
    for (auto &graph : graphs) {
      need.push_back(get(graph));
    }
    sort(need.begin(), need.end());
    for (auto &kek : need) {
      ///print(kek);
    }
    for (auto &second : verts) {
    ///  second = 3;
      graph.push_back({second, other});
      vector<vector<pair<T, T>>> have;
      for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> edges;
        for (auto &it : graph) {
          if (it.first == i || it.second == i) continue;
          edges.push_back(it);
        }
        have.push_back(get(edges));
      }
    //  cout << "\n";
      sort(have.begin(), have.end());
      for (auto &kek : have) {
    //    print(kek);
      }
      if (have == need) {
        cout << "YES\n";
        for (auto &edge : graph) {
          cout << edge.first << " " << edge.second << "\n";
        }
        cout << "\n";
        ok = 1;
        break;
      }
      graph.pop_back();
    }
    if (!ok) {
      cout << "NO\n";
    }
  }
  return 0;
}
/**



**/