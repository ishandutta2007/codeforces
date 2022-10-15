#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 18;
const int INF = (int) 1e9;
int n;
int m;
int dp[1 << N];
int who[1 << N];
int in[1 << N];
int c[1 << N];
int r[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    in[1 << y] |= 1 << x;
    c[1 << x] += w;
    c[1 << y] -= w;
  }

  for (int mask = 0; mask < (1 << n); mask++) {
    dp[mask] = INF;
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    int i = log2(mask);
    in[mask] = in[mask - (1 << i)] | in[1 << i];
    c[mask] = c[mask - (1 << i)] + c[1 << i];
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    if (in[mask] == 0) {
      dp[mask] = 0;
      who[mask] = mask;
    }
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
      if (in[sub] == (in[sub] & (mask ^ sub))) {
        int val = dp[mask ^ sub] + c[mask ^ sub];
        if (val < dp[mask]) {
          dp[mask] = val;
          who[mask] = sub;
        }
      }
    }
  }
  int mask = (1 << n) - 1, step = 0;
  while (mask) {
    int scap = who[mask];
    mask -= scap;
    while (scap) {
      int i = log2(scap);
      r[i] = step;
      scap -= (1 << i);
    }
    step++;
  }
  for (int i = 0; i < n; i++) {
    cout << r[i] << " ";
  }
  cout << "\n";
}