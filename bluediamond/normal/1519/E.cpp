#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();

time_t bg, nd;

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
  bg = clock();
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 4e5 + 7;
int n, a[N], b[N], c[N], d[N], yy, spec[N];
map<pair<int, int>, int> id;
int x[N], y[N];
bool vis[N], used[N];
vector<int> g[N];
vector<pair<int, int>> sol;
vector<int> ord;


void dfs(int a, int p = -1) {
  vis[a] = 1;
  for (auto &ind : g[a]) {
    int b = x[ind] + y[ind] - a;
    if (!vis[b]) {
      dfs(b, a);
      spec[b] = ind;
    }
  }
  ord.push_back(a);
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    /**
    x/y = ?
    x = a[i]/b[i]
    y = c[i]/d[i]
    x/y = (a[i]*d[i])/(b[i]*c[i])
    **/
    int v1, v2;
    {
      a[i] += b[i];
      int sus = a[i] * d[i], down = b[i] * c[i], g = __gcd(sus, down);
      sus /= g;
      down /= g;
      if (!id.count({sus, down})) {
        id[{sus, down}] = ++yy;
      }
      v1 = id[{sus, down}];
      a[i] -= b[i];
    }
    {
      c[i] += d[i];
      int sus = a[i] * d[i], down = b[i] * c[i], g = __gcd(sus, down);
      sus /= g;
      down /= g;
      if (!id.count({sus, down})) {
        id[{sus, down}] = ++yy;
      }
      v2 = id[{sus, down}];
      c[i] -= d[i];
    }
    x[i] = v1;
    y[i] = v2;
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  for (int i = 1; i <= yy; i++) {
    if (!vis[i]) {
      ord.clear();
      dfs(i);
      for (auto &a : ord) {
        vector<int> posi;
        for (auto &b : g[a]) {
          if (!used[b]) {
            if (b == spec[a]) {
              posi.push_back(b);
            }
          }
        }
        for (auto &b : g[a]) {
          if (!used[b]) {
            if (b != spec[a]) {
              posi.push_back(b);
            }
          }
        }
        while ((int) posi.size() >= 2) {
          int i1 = posi.back(); posi.pop_back();
          int i2 = posi.back(); posi.pop_back();
          used[i1] = used[i2] = 1;
          sol.push_back({i1, i2});
        }
      }

    }
  }
  {
    cout << (int) sol.size() << "\n";
    for (auto &it : sol) {
      cout << it.first << " " << it.second << "\n";
    }
  }
  return 0;
}