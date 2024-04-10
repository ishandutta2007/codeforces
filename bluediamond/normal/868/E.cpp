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
#define int ll
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

const int N = 50 + 7;
const int INF = (int) 1e9;
int n, m, from[2 * N], to[2 * N], dur[2 * N], start;
int dp[2 * N][N][N];
vector<int> g[N];

void add(int i, int j, int take) {
  from[m] = i;
  to[m] = j;
  dur[m] = take;
  g[i].push_back(m);
  m++;
}

int rec(int edge, int total, int sub) {
  if (total == 0) return 0;
  if (dp[edge][total][sub] != -1) return dp[edge][total][sub];
  if ((int) g[to[edge]].size() == 1) {
    dp[edge][total][sub] = rec(edge ^ 1, total - sub, total - sub) + dur[edge];
    return dp[edge][total][sub];
  }
  int sol = INF;
  int lo = 0, hi = INF;
  bool ok = (edge == 1 && total == 4 && sub == 4);
  while (lo <= hi) {
    int t = (lo + hi) / 2;
    int cntmin = 0;
    int nr = (int) g[to[edge]].size() - 1;
    for (auto &edge2 : g[to[edge]]) {
      if (edge2 == (edge ^ 1)) continue;
      for (int need = sub; need >= 1; need--) {
      ///  cout << from[edge] << "..." << to[edge] << " -> " << edge2 << " " << total << " " << need << "\n";
        if (rec(edge2, total, need) > t) {
          cntmin += need;
          break;
        }
      }
    }


    bool castig_eu = (cntmin < sub);

    if (castig_eu) {
      sol = t;
      hi = t - 1;
    } else {
      lo = t + 1;
    }
  }
  sol += dur[edge];
  dp[edge][total][sub] = sol;
  return sol;
}

int este[N];

int calc_sub(int a, int p = -1) {
  int sol = este[a];
  for (auto &ind : g[a]) {
    int b = to[ind];
    if (b != p) sol += calc_sub(b, a);
  }
  return sol;
}

signed realMain() {
  for (int i = 0; i < 2 * N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) dp[i][j][k] = -1;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y, take;
    cin >> x >> y >> take;
    add(x, y, take);
    add(y, x, take);
  }
  cin >> start;
  int cntnodes;
  cin >> cntnodes;
  vector<int> nodes(cntnodes);
  for (auto &x : nodes) cin >> x;
  for (auto &x : nodes) este[x]++;
  int ret = INF;
  for (auto &ind : g[start]) {
    ret = min(ret, rec(ind, (int) nodes.size(), calc_sub(to[ind], start)));
  }
  cout << ret << "\n";
  return 0;
}