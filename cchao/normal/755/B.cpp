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

set<string> f;
int n, m, k = 0;
string s;
int main() {
  scanf("%d%d", &n, &m);
  REP(i, n) {
    cin >> s;
    f.insert(s);
  }
  REP(i, m) {
    cin >> s;
    if (f.count(s)) k++;
  }
  n -= k;
  m -= k;
  for(int i = 0;; i ^= 1) {
    if (i == 0) {
      if (k) --k;
      else if (n) --n;
      else {
        puts("NO");
        return 0;
      }
    } else {
      if (k) --k;
      else if (m) --m;
      else {
        puts("YES");
        return 0;
      }
    }
  }
  return 0;
}