#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n, s;
int a[maxn];
vector<int> gr[maxn];

llong dp[maxn];

void dfs(int u, int p) {
  for (auto v: gr[u])
    if (v != p) dfs(v, u);
  static vector<llong> t;
  t.clear();
  llong sum = 0;
  for (auto v: gr[u])
    if (v != p) {
      t.push_back(dp[v]);
      sum += a[v];
    }
  sort(t.begin(), t.end());
  dp[u] = 0;
  if (u != p) {
    dp[u] = 1;
    --a[u];
  }
  while (a[u] and len(t)) {
    // clog << u << ' ' << a[u] << ' ' << t.back() << endl;
    dp[u] += 1 + t.back();
    --a[u];
    t.pop_back();
  }
  llong m = min((llong)a[u], sum);
  a[u] -= m;
  dp[u] += 2 * m;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  rep(i, n - 1) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  cin >> s;
  dfs(s, s);
  cout << dp[s];
  // rep1(i, n) clog << i << ' ' << dp[i] << endl;
  
  return 0;
}