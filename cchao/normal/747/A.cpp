#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int main() {
  LL n;
  cin >> n;
  for (LL i = sqrt(n) + 0.5; i >= 1; --i) {
    if (n % i == 0) {
      cout << i << ' ' << n / i << endl;
      break;
    }
  }
  return 0;
}