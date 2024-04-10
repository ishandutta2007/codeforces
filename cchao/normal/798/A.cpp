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
  string s;
  cin >> s;
  const int n = s.size();
  int diff = 0;
  for (int i = 0, j = n - 1; i < j; ++i, --j)
    diff += s[i] != s[j];
  if (diff > 1 || (diff == 0 && n % 2 == 0))
    puts("NO");
  else
    puts("YES");
  return 0;
}