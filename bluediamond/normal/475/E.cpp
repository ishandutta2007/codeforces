#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;
const int INF = (int) 1e9 + 7;
int n, m, weight[N];
vector<int> gi[N];
vector<int> g[N];
bool vis[N], act[N];

int sub[N];
vector<int> kds[N];

void build(int a) {
  kds[a].clear();
  vis[a] = 1;
  sub[a] = weight[a];
  for (auto &b : g[a]) {
    if (vis[b]) {
      continue;
    }
    build(b);
    sub[a] += sub[b];
    kds[a].push_back(sub[b]);
  }
}

bitset<N> ok;

int maxup[N], dep[N];
vector<int> nrml[N];

void dfs(int a, int p = -1) {
  assert(vis[a] == 0);
  vis[a] = 1;
  maxup[a] = dep[a];
  for (auto &b : gi[a]) {
    if (b == p) continue;
    if (vis[b] == 0) {
      nrml[a].push_back(b);
      dep[b] = 1 + dep[a];
      dfs(b, a);
      maxup[a] = min(maxup[a], maxup[b]);
      continue;
    } else {
      assert(vis[b] == 1);
      maxup[a] = min(maxup[a], dep[b]);
    }
  }
}

bool bri[N];

void db(int a, int pap) {
  for (auto &b : nrml[a]) {
    if (bri[b]) {
      db(b, b);
      g[pap].push_back(b);
      g[b].push_back(pap);
    } else {
      db(b, pap);
    }
  }
  if (a != pap) {
    weight[pap] += weight[a];
    weight[a] = 0;
  }


}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    gi[a].push_back(b);
    gi[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    weight[i] = 1;
  }

  dfs(1);

  for (int a = 1; a <= n; a++) {
  ///  cout << "\t\t\t\t" << a << " : " << dep[a] << " vs " << maxup[a] << "\n";
    for (auto &b : nrml[a]) {
    ///  cout << a << " -> " << b << "\n";
      if (maxup[b] == dep[b]) {
       /// cout << "bridge : " << a << " " << b << "\n";
        /// bridge a, b
        bri[b] = 1;
      }


    }
  }
  db(1, 1);
 /// exit(0);



  int sum_weights = 0;
  for (int i = 1; i <= n; i++) {
    sum_weights += weight[i];
  }
  assert(sum_weights == n);
  int print_sol = -INF;

  for (int root = 1; root <= n; root++) {
    if (weight[root] == 0) {
      continue;
    }
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
    }
    build(root);

    int all = 0;
    for (int i = 1; i <= n; i++) {
      all += weight[i] * weight[i];
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i]) {
        all += weight[i] * (sub[i] - weight[i]);
      }
    }
    vector<int> dims = kds[root];
    if (!dims.empty()) {
      if (*max_element(dims.begin(), dims.end()) > n / 2) {
        continue;
      }
    }

    int sm_dims = 0;
    for (auto &x : dims) {
      sm_dims += x;
    }

    assert(sm_dims + weight[root] == n);


    ok = 0;

    ok[0] = 1;
    for (auto &x : dims) {
      ok |= (ok << x);

    }
    for (int i = 0; i <= n; i++) {
      if (ok[i]) {
        print_sol = max(print_sol, all + i * (n - weight[root] - i));
        assert(ok[n - weight[root] - i] == 1);
      }
    }
  }

  cout << print_sol << "\n";

  exit(0);

  for (int i = 1; i <= n; i++) {
    for (auto &j : g[i]) {
      if (i < j) {
        cout << "edge " << i << " " << j << "\n";
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (weight[i] > 0) {
      cout << "weight[" << i << "] = " << weight[i] << "\n";
    }
  }
}