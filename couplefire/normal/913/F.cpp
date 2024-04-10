#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  return power(a, md - 2);
}

int main() {
  int n, P, Q;
  cin >> n >> P >> Q;
  int p = mul(P, inv(Q));
  vector< vector<int> > p_win(n + 1, vector<int>(n + 1, 0));
  p_win[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      add(p_win[i + 1][j], mul(p_win[i][j], power(p, j)));
      add(p_win[i + 1][j + 1], mul(p_win[i][j], power((1 - p + md) % md, i - j)));
    }
  }
  vector<int> p_strong(n + 1);
  for (int i = 1; i <= n; i++) {
    p_strong[i] = 1;
    for (int j = 1; j < i; j++) {
      sub(p_strong[i], mul(p_strong[j], p_win[i][j]));
    }
  }
  vector<int> res(n + 1);
  res[1] = 0;
  for (int i = 2; i <= n; i++) {
    res[i] = 0;
    for (int j = 1; j < i; j++) {
      int coeff = mul(p_strong[j], p_win[i][j]);
      int games = (res[j] + res[i - j]) % md;
      add(games, j * (j - 1) / 2 + j * (i - j));
      add(res[i], mul(coeff, games));
    }
    add(res[i], mul(i * (i - 1) / 2, p_strong[i]));
    res[i] = mul(res[i], inv((1 - p_strong[i] + md) % md));
  }
  cout << res[n] << endl;
  return 0;
}