#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
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

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k;
  ll limit;
  cin >> n >> limit >> k;
  limit--;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  //dp[cnt][position] = ?
  //cnt = 0..k
  //position = 0..n
  vector<vector<int>> dp(k, vector<int> (n, 0));
  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
  }

  vector<int> order, lim(n);


  {
    vector<pair<int, int>> porder;
    for (int i = 0; i < n; i++) {
      porder.push_back({a[i], i});
    }
    sort(porder.begin(), porder.end());
    for (int i = 0; i < n; i++) {
      order.push_back(porder[i].second);
    }
    int l = 0;
    while (l < n) {
      int r = l;
      while (r + 1 < n && a[order[r + 1]] == a[order[r]]) {
        r++;
      }
      for (int j = l; j <= r; j++) {
        lim[order[j]] = r;
      }
      l = r + 1;
    }
  }

  for (int cnt = 0; cnt + 1 < k; cnt++) {
    int cur = 0, nxt = 0;
    for (auto &i : order) {
      while (nxt <= lim[i]) {
        addup(cur, dp[cnt][order[nxt++]]);
      }
      dp[cnt + 1][i] = cur;
    }
    continue;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= lim[i]; j++) {
        addup(dp[cnt + 1][i], dp[cnt][order[j]]);
      }
    }
  }

  int sol = 0;
  for (int cnt = 0; cnt < k; cnt++) {
    for (int i = 0; i < n; i++) {
      if (limit - i - (ll) cnt * n >= 0) {
        addup(sol, mul(((limit - i - (ll) cnt * n) / n + 1) % M, dp[cnt][i]));
      }
    }
  }
  cout << sol << "\n";
  return 0;
}

/**

5 9 1 5 9


5 9 1 5 9

5 9
1 5
1 9
5 5
9 9

sol = 10
**/