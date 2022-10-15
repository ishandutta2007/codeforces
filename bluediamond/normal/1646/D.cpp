#include <bits/stdc++.h>

using namespace std;

bool home = 1;
const int N = (int)2e5 + 7;
int n, cost[N], solution[N];
vector<int> g[N];

struct Solution {
  int cnt;
  int sum;
};

Solution getBest(Solution a, Solution b) {
  if (a.cnt != b.cnt) {
    if (a.cnt > b.cnt) return a;
    return b;
  }
  if (a.sum < b.sum) return a;
  return b;
}

Solution operator + (Solution a, Solution b) {
  a.cnt += b.cnt;
  a.sum += b.sum;
  return a;
}

Solution dp[N][2];

void solve_rec(int a, int p = -1) {
  dp[a][1] = { 1, cost[a] };
  for (auto& b : g[a]) {
    if (b == p) continue;
    solve_rec(b, a);
    dp[a][0] = dp[a][0] + getBest(dp[b][0], dp[b][1]);
    dp[a][1] = dp[a][1] + dp[b][0];
  }
}

void reconst(int a, int type, int p = -1) {
  if (type == 1) solution[a] = cost[a];
  for (auto& b : g[a]) {
    if (b == p) continue;
    if (type == 1) reconst(b, 0, a);
    else {
      if (dp[b][0].cnt == getBest(dp[b][0], dp[b][1]).cnt && dp[b][0].sum == getBest(dp[b][0], dp[b][1]).sum) reconst(b, 0, a);
      else reconst(b, 1, a);
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin >> n;
  if (n == 2) {
    cout << "2 2\n1 1\n";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    cost[i] = (int)g[i].size() - 1;
  }
  solve_rec(1);
  Solution sol = getBest(dp[1][0], dp[1][1]);
  cout << sol.cnt << " " << sol.sum + n << "\n";
  if (sol.cnt == dp[1][0].cnt && sol.sum == dp[1][0].sum) reconst(1, 0); else reconst(1, 1);

  for (int i = 1; i <= n; i++)cout << solution[i] + 1 << " ";
  cout << "\n";
}