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

const int N = 14;
int n, a[N], pWin[N][N], conex[1 << N];
vector<int> bits[1 << N];

int onlyOut(int mask, int mask2) {
  assert((mask & mask2) == 0);
  int sol = 1;

  for (auto &i : bits[mask]) {
    for (auto &j : bits[mask2]) {
      sol = mul(sol, pWin[i][j]);
    }
  }
  return sol;
}

signed main() {
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        bits[i].push_back(j);
      }
    }
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pWin[i][j] = dv(a[i], add(a[i], a[j]));
    }
  }

  /// prima ctc = mask
  /**
  prob(mask) = conex(mask) * onlyOut(mask, 2^n - 1 - mask)

  **/
  /**

  conex(mask) = 1 - sum(conex(mask2) * onlyOut(mask2 mask - mask2)| mask2 = submask of mask)

  onlyOut(mask, mask2) = sum(win(i, j) | for all i, j in i, j)

  **/

  for (int mask = 1; mask < (1 << n); mask++) {
    int m = (mask - 1) & mask;

    conex[mask] = 1;
    while (m) {
      conex[mask] = add(conex[mask], -mul(conex[m], onlyOut(m, mask - m)));
      m = (m - 1) & mask;
    }
  }

  int sol = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    addup(sol, mul((int) bits[mask].size(), mul(conex[mask], onlyOut(mask, (1 << n) - 1 - mask))));
  }
  cout << sol << "\n";

  return 0;
}