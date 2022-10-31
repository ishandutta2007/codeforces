#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define F first
#define S second

int main() {
  string s;
  cin >> s;
  int x = s[0] - 'a';
  int y = s[1] - '1';
  int ans = 0;
  REPE(i, -1, 1) REPE(j, -1, 1) {
    int tx = x + i, ty = y + j;
    if (tx == x && ty == y) continue;
    if (tx < 0 || ty < 0) continue;
    if (tx == 8 || ty == 8) continue;
    ans++;
  }
  cout << ans << endl;
  return 0;
}