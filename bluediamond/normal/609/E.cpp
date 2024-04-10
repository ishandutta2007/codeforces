#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, m;
int x[N], y[N], z[N], id[N], sol[N];
int t[N], sz[N];

bool cmp(int i, int j) {
  return z[i] < z[j];
}

vector <pair <int, int>> ask[N];

int par(int i) {
  if (t[i] == i) {
    return i;
  } else {
    return t[i] = par(t[i]);
  }
}

void unite(int i, int j, int cost) {
  i = par(i);
  j = par(j);
  if (i == j) {
    return;
  }
  if (sz[i] < sz[j]) {
    swap(i, j);
  }
  /// sz[i] > sz[j], bag din j in i
  t[j] = i;
  sz[i] += sz[j];
  for (auto &id : ask[j]) {
    if (sol[id.first] == -1) {
      if (par(id.second) == i) {
        sol[id.first] = cost;
      } else {
        ask[i].push_back(id);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

///  freopen ("input", "r", stdin);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    t[i] = i;
    sz[i] = 1;
  }

  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> z[i];
    ask[x[i]].push_back({i, y[i]});
    ask[y[i]].push_back({i, x[i]});
    id[i] = i;
    sol[i] = -1;
  }
  sort(id + 1, id + m + 1, cmp);

  ll ans = 0;
  for (int j = 1; j <= m; j++) {
    int i = id[j];
    if (par(x[i]) != par(y[i])) {
      ans += z[i];
      unite(x[i], y[i], z[i]);
    }
  }

  for (int i = 1; i <= m; i++) {
    cout << ans - sol[i] + z[i] << "\n";
  }

  return 0;
}