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

char s[100010];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  REP(i, n - 1) if ((s[i] - '0') % 2 == 0) {
    if (s[i] < s[n - 1]) {
      swap(s[i], s[n - 1]);
      puts(s);
      return 0;
    }
  }
  for (int i = n - 2; i >= 0; --i) if ((s[i] - '0') % 2 == 0) {
    swap(s[i], s[n - 1]);
    puts(s);
    return 0;
  }
  puts("-1");
  return 0;
}