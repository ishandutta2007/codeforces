#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int ll
typedef long double ld;

const int M = (int) 1e9 + 7;

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

int dp[66][6];
bool bad[6][6];

int anti(int x) {
  return x ^ 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < 6; i++) {
    bad[i][i] = 1;
    bad[i][i ^ 1] = 1;
  }

  int k;
  cin >> k;

  for (int i = 0; i < 6; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= k; i++) {
    for (int top = 0; top < 6; top++) {
      vector<int> good;
      for (int i = 0; i < 6; i++) {
        if (!bad[top][i]) good.push_back(i);
      }
      for (auto &k1 : good) {
        for (auto &k2 : good) {
          addup(dp[i][top], mul(dp[i - 1][k1], dp[i - 1][k2]));
        }
      }
    }
  }

  int sol = 0;
  for (int i = 0; i < 6; i++) {
    addup(sol, dp[k][i]);
  }
  cout << sol << "\n";


  return 0;
}