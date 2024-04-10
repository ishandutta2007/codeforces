#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int sqr(int a) {
  return mul(a, a);
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

void addup(int &a, int b) {
  a = add(a, b);
}

const int N = 1000 + 7;
int n, m, a[N][N], r, c, dp[N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("input", "r", stdin);
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      v.push_back({a[i][j], {i, j}});
    }
  }
  sort(v.begin(), v.end());
  cin >> r >> c;
  int l = 0, sum = 0, sr = 0, sc = 0, sr2 = 0, sc2 = 0;
  while (l < (int) v.size()) {
    int last = l;
    while (last + 1 < (int) v.size() && v[last + 1].first == v[last].first) {
      last++;
    }
    int inv = dv(1, l), addsum = 0, addsr = 0, addsc = 0, addsr2 = 0, addsc2 = 0;
    for (int i = l; i <= last; i++) {
      int r = v[i].second.first, c = v[i].second.second;
      addup(dp[r][c], sum);
      addup(dp[r][c], mul(l, add(sqr(r), sqr(c))));
      addup(dp[r][c], sr);
      addup(dp[r][c], sc);
      addup(dp[r][c], -mul(2 * r, sr2));
      addup(dp[r][c], -mul(2 * c, sc2));
      dp[r][c] = mul(dp[r][c], inv);
      addsr2 = add(addsr2, r);
      addsc2 = add(addsc2, c);
      addsum = add(addsum, dp[r][c]);
      addsr = add(addsr, sqr(r));
      addsc = add(addsc, sqr(c));
    }
    addup(sum, addsum);
    addup(sr, addsr);
    addup(sc, addsc);
    addup(sr2, addsr2);
    addup(sc2, addsc2);
    l = last + 1;
  }
  cout << dp[r][c] << "\n";
  return 0;
}