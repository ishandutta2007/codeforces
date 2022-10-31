#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define PB push_back
string s;

vector<int> a[128];

int main() {
  cin >> s;
  const int n = s.size();
  int ans = n;
  REPE(i, 'a', 'z') a[i].PB(0);
  REP(i, n) a[s[i]].PB(i + 1);
  REPE(i, 'a', 'z') a[i].PB(n + 1);
  REPE(i, 'a', 'z') {
    int mx = 0;
    REPE(j, 1, SZ(a[i]) - 1) mx = max(mx, a[i][j] - a[i][j - 1]);
    ans = min(ans, mx);
  }
  printf("%d\n", ans);
  return 0;
}