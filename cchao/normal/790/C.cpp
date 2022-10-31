#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

int dp[76][76][76][2];
int n;
char s[110];
vector<int> a[3];
int b[3];

const int inf = 1e9;

int main() {
  scanf("%d%s", &n, s);
  REP(i, n) {
    int t = 2;
    if (s[i] == 'V') t = 0;
    else if (s[i] == 'K') t = 1;
    a[t].PB(i);
    b[t]++;
  }
  for (int i = b[0]; i >= 0; --i)
    for (int j = b[1]; j >= 0; --j)
      for (int k = b[2]; k >= 0; --k)
        for (int l = 0; l < 2; ++l) {
          int &r = dp[i][j][k][l];
          int p = (i + j + k);
          if (p == n) {
            r = 0;
            continue;
          }
          r = inf;
          if (i < b[0]) {
            int e = 0;
            REP(t, i) if (a[0][t] > a[0][i]) e++;
            REP(t, j) if (a[1][t] > a[0][i]) e++;
            REP(t, k) if (a[2][t] > a[0][i]) e++;
            r = min(r, dp[i+1][j][k][1] + abs(p - a[0][i] - e));
          }
          if (j < b[1] && l == 0) {
            int e = 0;
            REP(t, i) if (a[0][t] > a[1][j]) e++;
            REP(t, j) if (a[1][t] > a[1][j]) e++;
            REP(t, k) if (a[2][t] > a[1][j]) e++;
            r = min(r, dp[i][j+1][k][0] + abs(p - a[1][j] - e));
          }
          if (k < b[2]) {
            int e = 0;
            REP(t, i) if (a[0][t] > a[2][k]) e++;
            REP(t, j) if (a[1][t] > a[2][k]) e++;
            REP(t, k) if (a[2][t] > a[2][k]) e++;
            r = min(r, dp[i][j][k+1][0] + abs(p - a[2][k] - e));
          }
        }
  printf("%d\n", dp[0][0][0][0]);
  return 0;
}