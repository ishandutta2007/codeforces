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

string s[4];

bool ok(int *a) {
  return a['x'] == 2 && a['.'] == 1;
}

int main() {
  REP(i, 4) cin >> s[i];
  REP(i, 4) REP(j, 4) {
    int c[128] = {}, d[128] = {}, e[128]={}, f[128]={};
    REP(k, 3) {
      if (j < 2) c[s[i][j+k]]++;
      if (i < 2) d[s[i+k][j]]++;
      if (i < 2 && j < 2) e[s[i+k][j+k]]++;
      if (i < 2 && j >= 2) f[s[i+k][j-k]]++;
    }
    if (ok(c) || ok(d) || ok(e) || ok(f)) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}