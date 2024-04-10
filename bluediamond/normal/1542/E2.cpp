#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int M;


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

int func(int a) {
  return a * (a - 1) / 2;
}

const int S = 300000;
int n, dp[S], sz;
vector<int> ant, sum, grow, scad;

int fsum(int l, int r) {
  if (l > r) return 0;
  return add(sum[r], -sum[l - 1]);
}

int fgrow(int l, int r, int x) {
  if (l > r) return 0;
  int kek = add(grow[r], -grow[l - 1]);
  kek = add(kek, -mul(l, fsum(l, r)));
  kek = add(kek, mul(x, fsum(l, r)));
  return kek;
}

int fscad(int l, int r, int x) {
  if (l > r) return 0;
  int kek = add(scad[r], -scad[l - 1]);
  kek = add(kek, -mul(-l, fsum(l, r)));
  kek = add(kek, mul(x, fsum(l, r)));
  return kek;
}


int main() {
  cin >> n >> M;
  if (M == 1) {
    cout << "0\n";
    return 0;
  }
  int print = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    ant = sum = grow = scad = {};
    int extra = func(i + 1);
    int cur = 0;
    for (int j = -extra; j <= extra; j++) {
      ant.push_back(dp[abs(j)]);
      addup(cur, ant.back());
      sum.push_back(cur);
    }
    sz = (int) ant.size();
    int cur1 = 0, cur2 = 0;
    for (int j = 0; j < sz; j++) {
      addup(cur1, mul(j % M, ant[j]));
      addup(cur2, mul(add(0, -(j % M)), ant[j]));
      grow.push_back(cur1);
      scad.push_back(cur2);
    }
    for (int j = 0; j <= func(i); j++) {
      dp[j] = add(fscad(j + extra, j + (i - 1) + extra, i), fgrow(j - (i - 1) + extra, j - 1 + extra, 1));
    }
    print = mul(i, print);
    for (int dif = 1; dif <= i; dif++) {
      addup(print, mul(i - dif, fsum(dif + 1 + extra, sz - 1)));
    }
  }
  cout << print << "\n";
  return 0;
}