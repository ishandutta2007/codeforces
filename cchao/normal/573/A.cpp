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

int n, a[100010];

int main() {
  cin >> n;
  REP(i, n) cin >> a[i];
  int g = a[0];
  REP(i, n) g = __gcd(g, a[i]);
  REP(i, n) {
    a[i] /= g;
    while (a[i] % 2 == 0) a[i] /= 2;
    while (a[i] % 3 == 0) a[i] /= 3;
    if (a[i] != 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}