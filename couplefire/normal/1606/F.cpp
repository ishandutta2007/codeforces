#include <bits/stdc++.h>
using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
const int M = 555;
int n;
vector<int> g[N];
int dp[N][M];
int print[N];

void build(int a, int p = -1) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b == p) continue;
    build(b, a);
    kids.push_back(b);
  }
  g[a] = kids;
}

void fff(int a) {
  int stop = min(n, M - 1);
  for (int k = 0; k <= stop; k++) {
    dp[a][k] = 0;
  }
  for (auto &b : g[a]) {

    fff(b);
    for (int k = 0; k <= stop; k++) {
      dp[a][k] += max(1, dp[b][k] - k);
    }
  }
}

int nw[M], sub[N];

void dfs(int a) {
  for (int i = 0; i < M; i++) {
    dp[a][i] = -(int) 1e9;
  }
  int stop = min(n, M - 1);
  sub[a] = 1;
  dp[a][0] = 0;
  for (auto &b : g[a]) {
    dfs(b);
    for (int i = 0; i <= min(stop, sub[a] + sub[b]); i++) {
      nw[i] = dp[a][i];
    }
    for (int bef = 0; bef <= min(stop, sub[a]); bef++) {
      for (int fb = 0; bef + fb + 1 <= stop && fb <= sub[b]; fb++) {
        nw[bef + fb + 1] = max(nw[bef + fb + 1], dp[a][bef] + dp[b][fb]);
      }
    }
    sub[a] += sub[b];
    for (int i = 0; i <= min(stop, sub[a]); i++) {
      dp[a][i] = max(dp[a][i] + 1, nw[i]);
    }
  }

  for (int m = 1; m <= stop; m++) {
    dp[a][m] = max(dp[a][m], dp[a][m - 1]);
  }
}

struct qs {
  int a, k, i;
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  build(1);
  fff(1);

  int q;
  cin >> q;

  for (int i = 1; i <= q; i++) {
    print[i] = -1;
  }

  vector<qs> al, bl;
  for (int i = 1; i <= q; i++) {
    int a, k;
    cin >> a >> k;
   // k = min(k, n);
    if (k < M) {
      al.push_back({a, k, i});
    } else {
      bl.push_back({a, k, i});
    }
  }
  for (auto &it : al) {
    print[it.i] = dp[it.a][it.k];
  }
  dfs(1);
  for (auto &it : bl) {
    int a = it.a, k = it.k;
    int sol = 0;
    for (int dl = 0; dl <= min(n, M - 1); dl++) {
      sol = max(sol, dp[a][dl] - k * dl);
    }
    print[it.i] = sol;
  }
  for (int i = 1; i <= q; i++) {
    cout << print[i] << "\n";
  }
  return 0;
}