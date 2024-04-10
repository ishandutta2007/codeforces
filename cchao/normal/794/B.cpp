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

int main() {
  int n;
  double h;
  scanf("%d%lf", &n, &h);
  REPE(i, 1, n - 1) {
    printf("%.12f%c", sqrt(1.0 * i / n) * h, " \n"[i == n - 1]);
  }
  return 0;
}