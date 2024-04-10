#include <bits/stdc++.h>

using namespace std;

struct Oferta {
  int a, b, profit;
};

const int N = (int) 2e5 + 7;
const int K = 19;

int n, m, eulerTour[2 * N], top, ff[N], ss[N], dep[N], lg[2 * N], sum[N], dp[N], par[N], aib[N], st[N], dr[N], top2, opa[N];
pair<int, int> tab[K][2 * N];


void add(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int get(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}

vector<int> g[N];
vector<Oferta> oferte[N];

void build(int a) {
  st[a] = ++top2;
  opa[top2] = a;
  eulerTour[++top] = a;
  ff[a] = ss[a] = top;

  for (auto &b : g[a]) {

    dep[b] = 1 + dep[a];
    build(b);
    eulerTour[++top] = a;
    ss[a] = top;
  }
  dr[a] = top2;
}

int lca(int a, int b) {
  if (ff[a] > ss[b]) swap(a, b);
  a = ff[a];
  b = ss[b];
  assert(a <= b);
  int k = lg[b - a + 1];
  return min(tab[k][a], tab[k][b - (1 << k) + 1]).second;
}
void solve(int a) {
  for (auto &b : g[a]) {
    solve(b);
    sum[a] += dp[b];
  }
  add(st[a], sum[a]);
  add(dr[a] + 1, -sum[a]);
  dp[a] = sum[a];
  for (auto &kek : oferte[a]) {
    int x = kek.a, y = kek.b, profit = kek.profit;
    dp[a] = max(dp[a], get(st[x]) + get(st[y]) + profit - sum[a]);
  }
  sum[a] -= dp[a];
  add(st[a], -dp[a]);
  add(dr[a] + 1, dp[a]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int pp;
    cin >> pp;
    par[i] = pp;
    g[pp].push_back(i);
  }

  build(1);

  for (int i = 1; i <= top; i++) {
    tab[0][i] = {dep[eulerTour[i]], eulerTour[i]};
    if (i >= 2) lg[i] = 1 + lg[i / 2];
  }

  for (int k = 1; (1 << k) <= top; k++) {
    for (int i = 1; i + (1 << k) - 1 <= top; i++) {
      tab[k][i] = min(tab[k - 1][i], tab[k - 1][i + (1 << (k - 1))]);
    }
  }

  for (int i = 1; i <= m; i++) {
    int a, b, profit;
    cin >> a >> b >> profit;
    oferte[lca(a, b)].push_back({a, b, profit});
  }


  solve(1);
  cout << dp[1] << "\n";
  return 0;
}