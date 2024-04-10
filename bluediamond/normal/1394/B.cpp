#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));
const int N = (int) 2e5 + 7;
const int A = 3;
const int K = 9;
int n;
int m;
int k;
vector<pair<int, int>> edges[N];
vector<int> g[N];
ll a[A][N];
ll b[A][K][K];
ll w[A];
ll s[A];
int res;

void genall(int pos) {
  if (pos == k) {
    for (int j = 0; j < A; j++) {
      if (s[j] != w[j]) {
        return;
      }
    }
    res++;
    return;
  }
  for (int it = 0; it <= pos; it++) {
    for (int j = 0; j < A; j++) {
      s[j] += b[j][pos][it];
    }
    genall(pos + 1);
    for (int j = 0; j < A; j++) {
      s[j] -= b[j][pos][it];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int x, y, weight;
    cin >> x >> y >> weight;
    edges[x].push_back({weight, y});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < A; j++) {
      a[j][i] = rng();
      w[j] += a[j][i];
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(edges[i].begin(), edges[i].end());
    for (auto &it : edges[i]) {
      g[i].push_back(it.second);
    }
    if (g[i].empty()) {
      cout << "0\n";
      return 0;
    }
    for (int j = 0; j < A; j++) {
      for (int f = 0; f < (int) g[i].size(); f++) {
        b[j][(int) g[i].size() - 1][f] += a[j][g[i][f]];
      }
    }
  }
  genall(0);
  cout << res << "\n";
  return 0;
}