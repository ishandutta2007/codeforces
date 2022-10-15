#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n, l[N], r[N], top, sub[N], par[N];
vector<int> g[N];
ll cnt[N];

void dfs(int a, int p = -1) {
  par[a] = p;
  l[a] = ++top;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b != p) {
      dfs(b, a);
      sub[a] += sub[b];
    }
  }
  r[a] = ++top;
}

bool is_ancestor(int ancestor, int v) {
  return l[ancestor] <= l[v] && r[v] <= r[ancestor];
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    top = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(0);


    for (int i = 0; i <= n + 1; i++) {
      cnt[i] = 0;
    }

    cnt[0] = n * (ll) (n - 1) / 2;

    int a = 0, b = 1, pr = -1;

    for (int i = 1; i < n; i++) {
      if (is_ancestor(i, a) || is_ancestor(i, b)) {

      } else {
        assert(b != 0);
        if (is_ancestor(b, i)) {
          b = i;
        } else {
          if (is_ancestor(a, i)) {

            a = i;
            int pa = a;
            while (par[pa] != 0) {
              pa = par[pa];
            }
            if (pa == pr) {
              break;
            }
          } else {
            break;
          }
        }
      }

      if (pr == -1) {
        pr = b;
        while (par[pr] != 0) {
          pr = par[pr];
        }
      }

      assert(b != 0);

      if (a == 0) {

        assert(par[pr] == 0);
        cnt[i] = (sub[0] - sub[pr]) * (ll) (sub[b]);
      } else {
        cnt[i] = sub[a] * (ll) sub[b];
      }
    }
    ll sol = 0;
    for (auto &j : g[0]) {
      sol += sub[j] * (ll) (sub[j] - 1) / 2;
    }
    cnt[0] -= sol;
    cout << sol << " ";
    for (int i = 0; i < n; i++) {
      cout << cnt[i] - cnt[i + 1] << " ";
    }
    cout << "\n";
  }
}