/// bitset task
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int ll

const int N = 500 + 7;
const int K = 63;
int n, m;
bitset<N> ok[2][K][N];
bitset<N> oki[2][K][N];
bool kek[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, type;
    cin >> a >> b >> type;
    ok[type][0][a][b] = 1;
    oki[type][0][b][a] = 1;
  }

  for (int k = 1; k < K; k++) {
    for (int type = 0; type <= 1; type++) {
      for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
          if ((ok[type][k - 1][a] & oki[type ^ 1][k - 1][b]).any()) {
            ok[type][k][a][b] = 1;
            oki[type][k][b][a] = 1;
          }
        }
      }
    }
  }

  for (int a = 1; a <= n; a++) {
    if (ok[0][K - 1][1][a]) {
      cout << "-1\n";
      return 0;
    }
  }

  vector<pair<int, int>> posib;
  posib.push_back({1, 0});

  ll sol = 0;
  for (int bit = 60; bit >= 0; bit--) {
    for (int i = 1; i <= n; i++) {
      kek[i] = 0;
    }
    int other = (posib[0].second ^ 1);
    bool kwk = 0;
    for (auto &it : posib) {
      for (int i = 1; i <= n; i++) {
        if (ok[it.second][bit][it.first][i]) {
          kwk = 1;
          kek[i] = 1;
        }
      }
    }
    if (!kwk) continue;
    sol += (1LL << bit);
    posib.clear();
    for (int i = 1; i <= n; i++) {
      if (kek[i]) {
        posib.push_back({i, other});
      }
    }
  }
  if (sol > (ll) 1e18) {
    cout << "-1\n";
    return 0;
  }
  cout << sol << "\n";

  return 0;
}