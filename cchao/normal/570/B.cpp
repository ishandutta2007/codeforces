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
  int n, m;
  cin >> n >> m;
  if (n == 1) cout << 1 << endl;
  else if (m <= n / 2) cout << m + 1 << endl;
  else cout << m - 1 << endl;
  return 0;
}