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
  int k, n;
  cin >> k >> n;
  vector<int> a(k), b(k);
  REP(i, k) cin >> a[i];
  REP(i, k) cin >> b[i];
  int x = a[0], y = b[0];
  REP(i, k) a[i] -= x, b[i] -= y;
  REP(i, k) {
    if (a == b) break;
    b.erase(b.begin());
    b.push_back(n);
    y = b[0];
    REP(i, k) b[i] -= y;
  }
  puts(a == b ? "YES" : "NO");
  return 0;
}