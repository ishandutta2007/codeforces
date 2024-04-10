#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n;
vector<int> gr[maxn];

long double ans = 0;
llong d[maxn];
long double pro[maxn];

void dfs(int u, int p) {
  pro[u] /= (long double) len(gr[u]) - (u != 1);
  if (u != 1 and len(gr[u]) == 1) {
    //clog << u << ' ' << d[u] << ' ' << pro[p] << endl;
    ans += (long double)d[u] * pro[p];
  }
  for (auto v: gr[u]) {
    if (v != p) {
      pro[v] = pro[u];
      d[v] = d[u] + 1;
      dfs(v, u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  pro[1] = 1;
  d[1] = 0;
  dfs(1, 1);
  cout << fixed << setprecision(10) << ans;

  return 0;
}