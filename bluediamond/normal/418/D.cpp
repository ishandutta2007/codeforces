#include <bits/stdc++.h>

using namespace std;

void maxup(int &a, int b) {
  a = max(a, b);
}

const int N = (int) 2e5 + 7;
const int K = 19;
const int INF = (int) 1e9 + 7;
int n;
int up[K][N];
int maxdown[N];
int par[N];
int dep[N];
int ord[N], lft[N], rgh[N], topord;
int euler_tour[2 * N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
vector<int> g[N];
pair<int, int> tab_lca[2 * N][K];
int kek1[K][N];
multiset<int> s[N];
int maxdepdown[N];
int maxoth[K][N];
int pr[K][N];

void dfs_lca(int a, int pp = 0) {
  pr[0][a] = pp;
  s[a].insert(-1);
  s[a].insert(-1);
  s[a].insert(-1);
  maxdown[a] = 0;
  maxdepdown[a] = dep[a];
  par[a] = pp;
  up[0][a] = pp;
  ord[++topord] = a;
  lft[a] = topord;
  euler_tour[++tour_sz] = a;
  first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
  vector<int> Kids;
  for (auto &b : g[a]) {
    if (b == pp) continue;
    dep[b] = 1 + dep[a];
    dfs_lca(b, a);
    Kids.push_back(b);
    euler_tour[++tour_sz] = a;
    last_time_on_tour[a] = tour_sz;

    maxup(maxdown[a], 1 + maxdown[b]);
    s[a].insert(1 + maxdown[b]);
    maxup(maxdepdown[a], maxdepdown[b]);
  }
  rgh[a] = topord;

  g[a] = Kids;

  kek1[0][a] = -2 - dep[pp];

  for (int Iter = 1; Iter <= 2; Iter++) {
    reverse(Kids.begin(), Kids.end());
    int biggest = -INF;
    int biggest_kek = -INF;
    for (auto &b : Kids) {
      maxup(maxoth[0][b], biggest);
      maxup(biggest, maxdepdown[b]);


      maxup(kek1[0][b], biggest_kek);
      maxup(biggest_kek, maxdepdown[b] - 2 * (dep[b]));
    }
  }
}

void lcaTM() {
  dfs_lca(1);
  for (int i = 2; i <= tour_sz; i++) {
    lg2[i] = 1 + lg2[i / 2];
  }
  for (int i = 1; i <= tour_sz; i++) {
    tab_lca[i][0] = {dep[euler_tour[i]], euler_tour[i]};
  }
  for (int k = 1; (1 << k) <= tour_sz; k++) {
    for (int i = 1; i + (1 << k) - 1 <= tour_sz; i++) {
      tab_lca[i][k] = min(tab_lca[i][k - 1], tab_lca[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int get_lca(int a, int b) {
  if (first_time_on_tour[a] > last_time_on_tour[b]) {
    swap(a, b);
  }
  a = first_time_on_tour[a];
  b = last_time_on_tour[b];
  int k = lg2[b - a + 1];
  return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}

int get_dist(int a, int b) {
  return dep[a] + dep[b] - 2 * dep[get_lca(a, b)];
}

int go_up(int a, int by) {
  assert(by >= 0);
  for (int i = 0; i < K; i++) {
    if (by & (1 << i)) {
      a = up[i][a];
    }
  }
  return a;
}


int just_once(int b, int v1, int v2, int c) { /// optimize
  int sol = -INF;
  assert(get_lca(b, v1) != v1);
  assert(dep[get_lca(b, v1)] < dep[v1]);
  assert(get_lca(b, v1) == c);
  maxup(sol, 0);


  s[c].erase(s[c].find(1 + maxdown[v1]));
  s[c].erase(s[c].find(1 + maxdown[v2]));

  assert(!s[c].empty());
  auto it = s[c].end();
  it--;
  maxup(sol, *it);

  s[c].insert(1 + maxdown[v1]);
  s[c].insert(1 + maxdown[v2]);

  return sol + dep[b] - dep[c];
}

int compute(int a, int start, int stop) { /// optimize
  int sol = -INF;
  int rt = start;
  if (start != stop) {
    for (int bit = 0; (1 << bit) <= dep[start] - dep[stop]; bit++) {
      if ((dep[start] - dep[stop]) & (1 << bit)) {
        maxup(sol, maxoth[bit][rt]);
        rt = pr[bit][rt];
      }
    }
  }
  return sol + dep[a] - 2 * dep[par[stop]];
}

int compute3(int a, int start, int stop) { /// optimize
  int sol = -INF;
  int rt = start;
  if (start != stop) {
    for (int bit = 0; (1 << bit) <= dep[start] - dep[stop]; bit++) {
      if ((dep[start] - dep[stop]) & (1 << bit)) {
        maxup(sol, maxoth[bit][rt]);
        rt = pr[bit][rt];
      }
    }
  }
  return sol + dep[a] - 2 * dep[stop];
}


int compute2(int a, int start, int stop) { /// optimize
  int sol = -INF;
  int rt = start;
  if (start != stop) {
    for (int bit = 0; (1 << bit) <= dep[start] - dep[stop]; bit++) {
      if ((dep[start] - dep[stop]) & (1 << bit)) {
        maxup(sol, kek1[bit][rt]);
        rt = pr[bit][rt];
      }
    }
  }
  return sol + 2 + dep[a];
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  cin >> n;
  ///cout << "n = " << n << "\n";


  for (int i = 2; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  lcaTM();
  for (int k = 1; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      up[k][i] = up[k - 1][up[k - 1][i]];
    }
  }

  for (int k = 1; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      pr[k][i] = pr[k - 1][pr[k - 1][i]];
      maxoth[k][i] = max(maxoth[k - 1][i], maxoth[k - 1][pr[k - 1][i]]);
      kek1[k][i] = max(kek1[k - 1][i], kek1[k - 1][pr[k - 1][i]]);
    }
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    int c = get_lca(a, b);
    if (get_dist(a, c) < get_dist(b, c)) swap(a, b);


    assert(get_dist(a, c) >= get_dist(b, c));
    int len = get_dist(a, b);
    int half_len = len / 2;
    int mid_point = go_up(a, half_len);
    assert(1 <= mid_point && mid_point <= n);
    assert(a != c);

    int sol = 0;

    if (mid_point == c) {
      int rt = a;
      maxup(sol, maxdown[a]);
      maxup(sol, maxdown[b]);
      maxup(sol, compute2(a, a, go_up(a, dep[a] - dep[mid_point] - 1)));
      maxup(sol, compute2(b, b, go_up(b, dep[b] - dep[mid_point] - 1)));
      rt = go_up(a, dep[a] - dep[c] - 1);

      int v1 = go_up(a, dep[a] - dep[c] - 1);
      int v2 = go_up(b, dep[b] - dep[c] - 1);
      assert(par[v1] == par[v2]);
      assert(par[v1] == c);
      assert(par[v2] == c);


      for (auto &child : g[c]) { /// optimize
        if (child == v1 || child == v2) continue;
        maxup(sol, maxdown[child] + dep[b] - dep[c]);
      }

     /// cout << " : " << a << " " << b << " " << " " << c << " and " << v1 << "\n";

      maxup(sol, just_once(b, v1, v2, c));
      maxup(sol, compute2(b, c, 1));
      cout << sol << "\n";
      continue;
    }
    assert(mid_point != c);
    maxup(sol, maxdown[a]);
    maxup(sol, compute2(a, a, mid_point));
    if (b == c) {
      maxup(sol, compute3(b, mid_point, c));

    } else {
      int v1 = go_up(a, dep[a] - dep[c] - 1);
      int v2 = go_up(b, dep[b] - dep[c] - 1);

      maxup(sol, just_once(b, v1, v2, c));
      maxup(sol, maxdown[b]);
      maxup(sol, compute2(b, b, v2));
      maxup(sol, compute(b, mid_point, v1));
    ///  cout << "end\n";
    }
    maxup(sol, compute2(b, c, 1));
    cout << sol << "\n";
  }
}
/// to do : compute Lowest common ancestor