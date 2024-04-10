/// problema urata de tot, nu mi-a placut absolut deloc
#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
int n, ret;
int iau[N];
int nup[N];
vector<int> g[N];

void dfs(int a, int p = 0) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
      dfs(b, a);
    }
  }
  iau[a] = 0;
  for (auto &b : kids) {
    iau[a] = max(iau[a], nup[b]);
  }
  iau[a]++;
  nup[a] = 0;
  for (auto &b : kids) {
    nup[a] = max(nup[a], max(iau[b], nup[b]));
  }
  nup[a] += (int) kids.size() - 1;
  {
    int m1 = 0, m2 = 0;
    for (auto &b : kids) {
      if (nup[b] > m1) {
        m2 = m1;
        m1 = nup[b];
      } else {
        if (nup[b] > m2) {
          m2 = nup[b];
        }
      }
    }
    ret = max(ret, m1 + m2 + 1);
  }
  {
    int m1 = 0, m2 = 0;
    for (auto &b : kids) {
      int val = max(nup[b], iau[b]);
      if (val > m1) {
        m2 = m1;
        m1 = val;
      } else {
        if (val > m2) {
          m2 = val;
        }
      }
    }
    ret = max(ret, m1 + m2 + (int) g[a].size() - 2);
  }

}

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  cout << ret << "\n";
  return 0;
}