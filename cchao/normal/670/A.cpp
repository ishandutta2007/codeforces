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
  cin >> n;
  int a = 0, b = 0;
  int t = n / 7 * 2;
  a += t, b += t, n %= 7;
  b += min(n, 2);
  if (n == 6) a += 1;
  cout << a << ' ' << b << endl;
  return 0;
}