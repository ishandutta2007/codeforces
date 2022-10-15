#include <bits/stdc++.h>

bool home = 1;
using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
ll gain[N];
ll down[N];
ll one[N];
ll one_and[N];
ll sol;
vector<int> g[N];

void dfs(int a, int parrent = -1) {
  {
    vector<int> kids;
    for (auto &b : g[a]) {
      if (b != parrent) {
        kids.push_back(b);
        dfs(b, a);
      }
    }
    g[a] = kids;
  }

  {
    /// down[a] && one[a]

    down[a] = gain[a];


    for (auto &b : g[a]) {
      one[a] = max(one[a], down[a] + down[b]);
      one[a] = max(one[a], one[b]);
      down[a] = max(down[a], down[b] + gain[a]);
    }
    one[a] = max(one[a], down[a]);
  }

  {
    /// one_and[a]
    one_and[a] = one[a];
    ll F = 0, S = 0;
    for (auto &b : g[a]) {
      one_and[a] = max(one_and[a], gain[a] + one_and[b]);
      one_and[a] = max(one_and[a], F + gain[a] + one[b]);
      one_and[a] = max(one_and[a], down[b] + gain[a] + S);
      F = max(F, down[b]);
      S = max(S, one[b]);
    }
  }

  {
    /// combine
    sol = max(sol, down[a]);
    sol = max(sol, one[a]);
    sol = max(sol, one_and[a]);

    ll P = 0;

    for (auto &b : g[a]) {
      sol = max(sol, one[b] + P);
      P = max(P, one[b]);
    }
    {
      ll T = 0;
      ll dw = 0;
      ll on = 0;
      ll dwdw = 0;
      ll ondw = 0;

      for (auto &b : g[a]) {
        T = max(T, dwdw + one[b]);
        T = max(T, ondw + down[b]);
        ondw = max(ondw, one[b] + dw);
        ondw = max(ondw, down[b] + on);
        dwdw = max(dwdw, down[b] + dw);
        dw = max(dw, down[b]);
        on = max(on, one[b]);
      }
      sol = max(sol, T + gain[a]);
    }
    {
      ll F = 0, S = 0;
      for (auto &b : g[a]) {
        sol = max(sol, one_and[b] + gain[a] + S);
        sol = max(sol, F + gain[a] + down[b]);
        F = max(F, one_and[b]);
        S = max(S, down[b]);
      }
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> gain[i];

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1);
  cout << sol << "\n";
}