#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 1e18;

const int N = 607;
ll req[N][N];
ll ed[N][N];

ll f[N][N];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ed[i][j] = INF;
      req[i][j] = 0;
    }
    ed[i][i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;

    ed[u][v] = w;
    ed[v][u] = w;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      f[i][j] = ed[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    req[u-1][v-1] = w;
    req[v-1][u-1] = w;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        req[j][k] -= f[i][j];
      }
    }

    vector<ll> mx(n, -INF);
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        mx[k] = max(mx[k], req[j][k]);
      }
    }

    for (int j = 0; j < n; ++j) {
      bool can = false;
      if (j==i || ed[i][j] == INF) continue;
      for (int k = 0; k < n; ++k) {
        if (ed[i][j] + f[j][k] <= mx[k]) {
          can = true;
        }
      }
      if (can) {
        ans++;
      }
    }

    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        req[j][k] += f[i][j];
      }
    }

  }

  cout << ans/2;



}