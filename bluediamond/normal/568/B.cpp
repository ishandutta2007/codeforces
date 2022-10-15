#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
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

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = 4000 + 7;
int n, comb[N][N], part[N][N], no[N], ret;

signed realMain() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    comb[i][0] = 1;
    part[i][0] = (i == 0);
    for (int j = 1; j <= i; j++) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
      part[i][j] = add(part[i][j], part[i - 1][j - 1]);
      part[i][j] = add(part[i][j], mul(part[i - 1][j], j));
    }
    for (int j = 0; j <= i; j++) {
      no[i] = add(no[i], part[i][j]);
    }
  }
  for (int cnt = 1; cnt <= n; cnt++) {
    int ways = comb[n][cnt];
    ways = mul(ways, no[n - cnt]);
    ret = add(ret, ways);
  }
  cout << ret << "\n";
  return 0;
}