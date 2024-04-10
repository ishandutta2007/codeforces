#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

///#pragma GCC target("avx2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


signed main() {
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

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = (int) 2e5 + 7;
int n, depe[N][3], sum[N], dp[N][3], pre[N], suf[N];
vector<int> g[N];
/// dp[a][0] = kiss
/// dp[a][1] = marry
/// dp[a][2] = kill

void dfs(int a, int indp = 0) {
  vector<int> kids;
  int d = 0;
  for (auto &ind : g[a]) {
    if (ind == indp) {
      d = (int) kids.size();
      continue;
    }
    int b = sum[ind] - a;
    kids.push_back(b);
    dfs(b, ind);
  }
  g[a] = kids;
  int sz = (int) g[a].size();
  for (int i = 1; i <= sz; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = depe[kids[i - 1]][j];
    }
  }
  pre[0] = 1;
  for (int i = 1; i <= sz; i++) {
    pre[i] = mul(pre[i - 1], add(dp[i][0], dp[i][1]));
  }
  suf[sz + 1] = 1;
  for (int i = sz; i >= 1; i--) {
    suf[i] = mul(suf[i + 1], add(dp[i][0], dp[i][2]));
  }
  { /// dp[a][0]
    for (int i = 1; i <= d; i++) {
      int prod = pre[i - 1];
      prod = mul(prod, dp[i][2]);
      prod = mul(prod, suf[i + 1]);
      depe[a][0] = add(depe[a][0], prod);
    }
  }
  { /// dp[a][1]
    int prod = pre[d];
    prod = mul(prod, suf[d + 1]);
    depe[a][1] = prod;
  }
  { /// dp[a][2]
    /// fie castiga mereu, fie moare dupa batalie :))))
    int prod = pre[sz];
    depe[a][2] = prod;
    for (int i = d + 1; i <= sz; i++) {
      int prod = pre[i - 1];
      prod = mul(prod, dp[i][2]);
      prod = mul(prod, suf[i + 1]);
      depe[a][2] = add(depe[a][2], prod);
    }
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    sum[i] = x + y;
    g[x].push_back(i);
    g[y].push_back(i);
  }
  dfs(1);
  cout << depe[1][2] << "\n";
  return 0;
}