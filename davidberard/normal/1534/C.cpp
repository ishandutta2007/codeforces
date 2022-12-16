#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 400400;
const ll MOD = 1e9+7;
int nxt[N], a[N], b[N];

bool seen[N];
bool cur[N];

int dfs(int u, int d) {
  if (seen[u]) {
    assert(cur[u]);
    return d;
  }
  seen[u] = 1;
  cur[u] = 1;
  int res = dfs(nxt[u], d+1);
  cur[u] = 0;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      seen[i] = 0;
      cin >> a[i];
    }
    for (int i=1; i<=n; ++i) {
      cin >> b[i];
      nxt[a[i]] = b[i];
    }
    int cnt = 0;
    for (int i=1; i<=n; ++i) {
      if (!seen[i]) {
        dfs(i, 0);
        ++cnt;
      }
    }
    ll ans = 1;
    for (int i=0; i<cnt; ++i) {
      ans = ans*2%MOD;
    }
    cout << ans << '\n';
  }
  return 0;
}