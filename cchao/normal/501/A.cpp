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

LL f(LL p, LL t) {
  return max(3 * p / 10, p - p / 250 * t);
}

int main() {
  LL a, b, c, d;
  cin >> a >> b >> c >> d;
  LL x = f(a, c);
  LL y = f(b, d);
  if (x < y) cout << "Vasya" << endl;
  else if (x > y) cout << "Misha" << endl;
  else cout << "Tie" << endl;
  return 0;
}