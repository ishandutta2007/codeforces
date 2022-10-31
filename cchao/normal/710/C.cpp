#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define F first
#define S second

int a[55][55] = {{}}, n;

int main() {
  cin >> n;
  int x = 0, y = n / 2, no = 0;
  REP(i, n * n) {
    assert(a[x][y] == 0);
    a[x][y] = ++no;
    x = (x + (n - 1)) % n;
    y = (y + 1) % n;
    if (a[x][y]) {
      x = (x + 2) % n;
      y = (y + (n - 1)) % n;
    }
  }
  REP(i, n) REP(j, n) printf("%d%c", a[i][j], " \n"[j == n - 1]);
  return 0;
}