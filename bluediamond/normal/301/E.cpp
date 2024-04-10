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

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N = 107;
int comb[N][N];

int cnt_at_least0(int n, int sum) {
  /**
  cnt(n, 0) = 1
  cnt(n, 1) = n
  cnt(n, 2) = n * (n + 1) / 2
  **/

  return comb[n + sum - 1][sum];
}

int cnt_at_least1(int sum, int n) {
  assert(sum >= n);
 /// cout << sum << " " << n << "\n";
  return cnt_at_least0(n, sum - n);
}

struct State {
  int len;
  int holes;
  int prod;
};

bool operator < (State a, State b) {
  if (a.len != b.len) {
    return a.len < b.len;
  }
  if (a.holes != b.holes) {
    return a.holes < b.holes;
  }
  return a.prod < b.prod;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  for (int i = 0; i < N; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = min(N, comb[i - 1][j] + comb[i - 1][j - 1]);
    }
  }

  int n, m, k;
  cin >> n >> m >> k;

  map<State, int> dp;
  for (int i = 1; i <= n; i++) {
    addup(dp[{i, i, 1}], +1);
  }

  int print_sol = 0;

  for (int x = 1; x <= m; x++) {
    map<State, int> ndp;
    for (auto &itP : dp) {
      State it = itP.first;
      int coef = itP.second;
      if (it.holes == 0) {
        addup(print_sol, coef);
        addup(ndp[it], coef);
        continue;
      }
      assert(it.holes > 0);
      for (int place = it.holes; it.len + place <= n; place++) {
        if (it.prod * cnt_at_least1(place, it.holes) <= k) {
          addup(ndp[{it.len + place, place - it.holes, it.prod * cnt_at_least1(place, it.holes)}], coef);
        }
      }
    }
    dp = ndp;
  }
  cout << print_sol << "\n";

  return 0;
}