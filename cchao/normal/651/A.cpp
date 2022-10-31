#include <bits/stdc++.h>
using namespace std;

int dp[222][222];
bool v[222][222];

int f(int a, int b) {
  int &r = dp[a][b];
  if (v[a][b]) return r;
  v[a][b] = true;
  r = 0;
  if (a >= 2) r = max(r, f(a - 2, b + 1) + 1);
  if (b >= 2) r = max(r, f(a + 1, b - 2) + 1);
  return r;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << max(f(a, b) - 1, 0) << endl;
  return 0;
}