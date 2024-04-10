#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 301010
int n;
int func[maxn];
vector<int> gr[maxn];

int ans[maxn];
int nleaf[maxn];
void dfs(int u) {
  nleaf[u] = 0;
  if (!len(gr[u])) {
    nleaf[u] = 1;
    ans[u] = 1;
    return ;
  }
  pair<int, int> potential(INT_MAX, 0);
  int sum_p = 0;
  for (auto v: gr[u]) {
    dfs(v);
    nleaf[u] += nleaf[v];
    potential = min(potential, {nleaf[v] - ans[v], v});
    sum_p += nleaf[v] - ans[v] + 1;
  }
  if (func[u] == 0) {
    ans[u] = nleaf[u] - sum_p + 1;
  } else {
    ans[u] = nleaf[u] - potential.xx;
  }
  // clog << u << endl;
  // clog << potential.xx << ' ' << sum_p << ' ' << func[u] << ' ' << nleaf[u] << ' ' <<  ans[u] << endl;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) cin >> func[i];
    for (int i = 2; i <= n; ++i) {
      int p; cin >> p;
      gr[p].push_back(i);
    }

    dfs(1);
    cout << ans[1];

    return 0;
}