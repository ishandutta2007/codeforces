#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
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

int mul(int a, int b, int c) {
  return mul(a, mul(b, c));
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 1000 + 7;
int n, m, dp[N][N], mni[N][N];
int c[N], mn[N], mx[N];
bool is[N];
vector<int> pos[N];

signed realMain() {
  cin >> n >> m;
  vector<int> vec;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    while (!vec.empty() && vec.back() == x) {
      vec.pop_back();
    }
    vec.push_back(x);
    is[x] = 1;
  }
  m = (int) vec.size();
  for (int i = 1; i <= n; i++) {
    if (!is[i]) {
      cout << "0\n";
      return 0;
    }
  }
  if (m > 2 * n) {
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    c[i] = vec[i - 1];
    mx[c[i]] = i;
    pos[c[i]].push_back(i);
  }
  for (int i = m; i >= 1; i--) {
    mn[c[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    mni[i][i] = c[i];
    for (int j = i + 1; j <= m; j++) {
      mni[i][j] = min(mni[i][j - 1], c[j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      dp[i][j] = 1;
    }
  }
  for (int l = m; l >= 1; l--) {
    for (int r = l; r <= m; r++) {
      /// dp[l][r] = ?
      bool all = 1;
      for (int i = l; i <= r; i++) {
        int x = c[i];
        if (mn[x] < l || mx[x] > r) {
          all = 0;
          break;
        }
      }
      if (!all) {
        continue;
      }
      int x = mni[l][r], a = 0, b = 0;
      for (int f = l; f <= mn[x]; f++) {
        int bag = 1;
        bag = mul(bag, dp[f][mn[x] - 1]);
        bag = mul(bag, dp[l][f - 1]);
        a = add(a, bag);
      }
      for (int s = mx[x]; s <= r; s++) {
        int bag = 1;
        bag = mul(bag, dp[mx[x] + 1][s]);
        bag = mul(bag, dp[s + 1][r]);
        b = add(b, bag);
      }
      dp[l][r] = mul(a, b);
      for (int j = 0; j + 1 < (int) pos[x].size(); j++) {
        int ff = pos[x][j] + 1, ss = pos[x][j + 1] - 1;
        dp[l][r] = mul(dp[l][r], dp[ff][ss]);
      }
    }
  }

  cout << dp[1][m] << "\n";
  return 0;
}