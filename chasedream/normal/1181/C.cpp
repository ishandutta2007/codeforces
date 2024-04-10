#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;

char c[N][N];
int d[N][N];

int n, m;

char get_ch() {
  char op = getchar();
  while (op < 'a' || op > 'z') op = getchar();
  return op;
}

bool ok(int x, int y) {
  int t = d[x][y];
  return d[x + t][y] == t && d[x + 2 * t][y] >= t;
}

void sao() {
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == c[i + 1][j])
        d[i][j] = d[i + 1][j] + 1;
      else
        d[i][j] = 1; 
    }
  }
}

void calc() {
  ll ans = 0ll;
  for (int i = 1; i <= n; i++) {
    int pp = 1;
    while (pp <= m) {
      if (!ok(i, pp)) {
        pp++; continue;
      }
      int kk = pp + 1, orz = d[i][pp];
      while (ok(i, kk) && d[i][kk] == orz &&
             c[i][kk] == c[i][pp] && c[i + orz][kk] == c[i + orz][pp] &&
             c[i + 2 * orz][kk] == c[i + 2 * orz][pp])
        kk++;
      
      ll add = (ll)(kk - pp) * (kk - pp + 1) / 2;
      //printf("%d %d: %lld\n", i, pp, add);
      ans += add;
      
      pp = kk;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      c[i][j] = get_ch();
    }
  sao();
  calc();
  return 0;
}