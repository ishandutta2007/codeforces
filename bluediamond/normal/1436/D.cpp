#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 2e5 + 7;
int n;
int a[N];
int cnt[N];
int sum[N];
int sol;
vector<int> g[N];

void dfs(int x) {
  sum[x] = a[x];
  cnt[x] = g[x].empty();
  for (auto &y : g[x]) {
    dfs(y);
    cnt[x] += cnt[y];
    sum[x] += sum[y];
  }
  sol = max(sol, (sum[x] + cnt[x] - 1) / cnt[x]);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1);
  cout << sol << "\n";



}