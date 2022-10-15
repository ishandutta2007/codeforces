#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 3e5 + 7;
int n, a[N], dp[N], pos[N];
map<int, int> nxt[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dp[i] = 0;
      pos[i] = -1;
    }
    dp[n + 1] = 0;
    for (int l = n; l >= 1; l--) {
      if (nxt[l + 1].count(a[l])) {
        pos[l] = nxt[l + 1][a[l]];
        swap(nxt[l], nxt[pos[l] + 1]);
      }
      nxt[l][a[l]] = l;
    }
    for (int l = n; l >= 1; l--) {
      if (pos[l] != -1) {
        dp[l] = dp[pos[l] + 1] + 1;
      }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      ret += dp[i];
      nxt[i].clear();
    }
    nxt[n + 1].clear();
    cout << ret << "\n";
  }
}