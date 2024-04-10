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

const int N = 5000 + 7;
int n;
int k;
string str;
int a[N], sum[N], comb[N][N];
int sol;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  for (int i = 0; i < N; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
    }
  }

  cin >> n >> k >> str;
  for (int i = 1; i <= n; i++) {
    a[i] = str[i - 1] - '0';
    sum[i] = sum[i - 1] + a[i];
  }

  if (k > sum[n]) {
    cout << "1\n";
    return 0;
  }

  addup(sol, 1); /// rems the same

  for (int f = 1; f <= n; f++) {
    for (int s = f + 1; s <= n; s++) {
      if (sum[s] - sum[f - 1] <= k) {
        int inside_place = s - f - 1;
        int ones_inside = sum[s] - sum[f - 1] - (a[s] == 0) - (a[f] == 0);
        if (ones_inside >= 0) {
          addup(sol, comb[inside_place][ones_inside]);
        }
      }
    }
  }
  cout << sol << "\n";



  return 0;
}