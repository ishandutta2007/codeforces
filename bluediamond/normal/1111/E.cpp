#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int K = 18;
int n;
int p[N];
int dep[N];
int l[N];
int r[N];
int tt;
int euler_tour[2 * N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
vector<int> g[N];
pair<int, int> tab_lca[2 * N][K];

void dfs_lca(int a, int pp = 0) {
  l[a] = ++tt;
  p[a] = pp;
  euler_tour[++tour_sz] = a;
  first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
  for (auto &b : g[a]) {
    if (b == pp) continue;
    dep[b] = 1 + dep[a];
    dfs_lca(b, a);
    euler_tour[++tour_sz] = a;
    last_time_on_tour[a] = tour_sz;
  }
  r[a] = tt;
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

int lca(int a, int b) {
  if (first_time_on_tour[a] > last_time_on_tour[b]) {
    swap(a, b);
  }
  a = first_time_on_tour[a];
  b = last_time_on_tour[b];
  int k = lg2[b - a + 1];
  return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int aib[N];

void add_aib(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int get_aib(int i) {
  int ret = 0;
  while (i) {
    ret += aib[i];
    i -= i & (-i);
  }
  return ret;
}

void baga(int i, int x) {
  add_aib(l[i], x);
  add_aib(r[i] + 1, -x);
}

int peste(int i) {
  return get_aib(l[i]);
}

int pe_drum(int a, int b) {
  int c = lca(a, b), c2 = p[c];
  return peste(a) + peste(b) - peste(c) - peste(c2);
}

int dp[333];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ///freopen ("input", "r", stdin);
  cin >> n;
  int q;
  cin >> q;
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  lcaTM();
  while (q--) {
    int cnt, k, r;
    cin >> cnt >> k >> r;
    vector<pair<int, int>> nodes(cnt);
    for (auto &x : nodes) {
      cin >> x.second;
      baga(x.second, +1);
    }
    for (auto &x : nodes) {
      x.first = pe_drum(x.second, r) - 1;
    }
    for (auto &x : nodes) {
      baga(x.second, -1);
    }
    sort(nodes.begin(), nodes.end());
    /**for (auto &it : nodes) {
      cout << it.second << " : " << it.first << "\n";
    }**/
    dp[0] = 1;
    for (int j = 1; j <= k; j++) {
      dp[j] = 0;
    }
    for (int i = 1; i <= cnt; i++) {
      int v = nodes[i - 1].second;
      for (int j = k; j >= 0; j--) {
        if (j >= nodes[i - 1].first) dp[j] = mul(dp[j], j - nodes[i - 1].first);
        else dp[j] = 0;
        if (j - 1 >= 0) dp[j] = add(dp[j], dp[j - 1]);
      }
    }
    int ret = 0;
    for (int j = 1; j <= k; j++) {
      ret = add(ret, dp[j]);
    }
    cout << ret << "\n";
  }
}