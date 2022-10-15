#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

const int N = 5000 + 7;
int cnt[N][N]; /// cnt[i][different]

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  cnt[0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (int dif = 0; dif <= i; dif++) {
      if (!cnt[i][dif]) continue;
      cnt[i + 1][dif] = add(cnt[i + 1][dif], mul(cnt[i][dif], dif));
      cnt[i + 1][dif + 1] = add(cnt[i + 1][dif + 1], mul(cnt[i][dif], n - dif));
    }
  }
  /**
  expected number of x^k = expected number of number of k TUPLETS such that every single one inside of the TUPLET is a joker
  e(number of k TUPLETS) = sum(TUPLET, Probability that it is a TUPLET)
  **/
  int ret = 0;
  for (int distinct = 1; distinct <= k; distinct++) {
    ret = add(ret, mul(dv(1, pw(m, distinct)), cnt[k][distinct]));
  }
  cout << ret << "\n";
}