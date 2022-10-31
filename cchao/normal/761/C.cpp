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

string s[55];
int d[55][3];
int n, m;

void R(string &s, int *d) {
  cin >> s;
  d[0] = d[1] = d[2] = 1e8;
  REP(i, m) {
    char c = s[i];
    int type = 2;
    if (isdigit(c)) {
      type = 0;
    } else if (isalpha(c)) {
      type = 1;
    }
    d[type] = min(d[type], min(i, m - i));
  }
}

int main() {
  cin >> n >> m;
  REP(i, n) {
    R(s[i], d[i]);
  }
  int ans = INT_MAX;
  REP(i, n) REP(j, n) REP(k, n) {
    if (i == j || j == k || i == k) continue;
    ans = min(ans, d[i][0] + d[j][1] + d[k][2]);
  }
  printf("%d\n", ans);
  return 0;
}