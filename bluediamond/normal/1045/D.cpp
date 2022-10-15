#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N = (int) 1e5 + 7;
int n;
int par[N];
ld p[N];
ld val[N];
ld sum;
ld sol;
vector<int> g[N];
vector<int> g2[N];

void build(int a, int pr) {
  if (pr != -1) {
    val[pr] += p[a];
  }
  par[a] = pr;
  for (auto &b : g[a]) {
    if (b != pr) {
      g2[a].push_back(b);
      build(b, a);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] = 1 - p[i];
    sum += p[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build(0, -1);
  for (int i = 0; i < n; i++) {
    g[i] = g2[i];
  }
  ld sol = 0;
  for (int i = 0; i < n; i++) {
    sol += p[i] * val[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int a;
    ld x;
    cin >> a >> x;
    x = 1 - x;
    sol -= p[a] * val[a];
    if (par[a] != -1) {
      sol -= p[par[a]] * val[par[a]];
      val[par[a]] -= p[a];
    }
    sum -= p[a];
    p[a] = x;
    sum += p[a];
    if (par[a] != -1) {
      val[par[a]] += p[a];
      sol += p[par[a]] * val[par[a]];
    }
    sol += p[a] * val[a];
    cout << fixed << setprecision(6) << sum - sol << "\n";
  }
}