#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int main() {
  int n;
  cin >> n;
  cout << n / 2 << endl;
  while (n) {
    int t = n % 2 == 0 ? 2 : 3;
    n -= t;
    printf("%d%c", t, " \n"[n == 0]);
  }
  return 0;
}