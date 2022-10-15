#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 100000 + 7;
const ld SMALL = 1e-10;
const ld EPS = 1e-14;
const ld INF = (ld) 1e9;
int n, m;
vector<pair<int, int>> g[N];
vector<int> nodes;
bool vis[N];
int par[N];
ll a[N];
ll b[N];
ld sol[N];

void dfs(int i) {
  nodes.push_back(i);
  vis[i] = 1;
  for (auto &it : g[i]) {
    int j = it.first;
    ll s = it.second;
    if (vis[j] == 0) {
      par[j] = i;
      a[j] = -a[i];
      b[j] = s - b[i];
      dfs(j);
    }
  }
}

struct T {
  int x;
  int y;
  ll s;
};

ld get(ld x, ld y, vector<pair<ll, ll>> sol) {
  ld sum = 0;
  for (auto &it : sol) {
    sum += fabs(x * it.first + it.second);
    sum -= fabs(y * it.first + it.second);
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      nodes.clear();
      a[i] = 1;
      b[i] = 0;
      dfs(i);
      vector<T> edges;
      for (auto &x : nodes) {
        for (auto &it : g[x]) {
          edges.push_back({x, it.first, it.second});
        }
      }
      bool found = 0;
      for (auto &it : edges) {
        int x = it.x;
        int y = it.y;
        ll s = it.s;
        if (a[x] == -a[y] && b[x] + b[y] != s) {
          cout << "NO\n";
          return 0;
        }
      }
      for (auto &it : edges) {
        int x = it.x;
        int y = it.y;
        ll s = it.s;
        if (a[x] == a[y]) {
          found = 1;
          sol[i] = ((ld) (s - (b[x] + b[y]))) / ((ld) (a[x] + a[y]));
          continue;
        }
      }
      if (found == 0) {
        vector<pair<ll, ll>> coefs;
        for (auto &j : nodes) {
          coefs.push_back({a[j], b[j]});
        }
        ld lo = -INF, hi = INF;
        for (int it = 1; it <= 200; it++) {
          ld mid = (lo + hi) * 0.5;
          if (get(mid - SMALL, mid, coefs) > -EPS) {
            lo = mid;
          } else {
            hi = mid;
          }
        }
        sol[i] = lo;
      }
      for (auto &j : nodes) {
        sol[j] = sol[i] * a[j] + b[j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto &it : g[i]) {
      int j = it.first;
      if (fabs(sol[i] + sol[j] - it.second) > EPS) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(6) << sol[i] << " ";
  }
  cout << "\n";
  return 0;
}