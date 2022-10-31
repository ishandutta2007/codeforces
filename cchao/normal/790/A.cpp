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

char s[55];
string ans[55];

string f(int x) {
  string ret = "A";
  while (x > 0) {
    ret += char('a' + (x % 26));
    x /= 26;
  }
  return ret;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  REP(i, k - 1) ans[i] = f(i + 1);
  REP(i, n - k + 1) {
    scanf("%s", s);
    if (s[0] == 'N') {
      ans[i + k - 1] = ans[i];
    } else ans[i + k - 1] = f(i + k + 1);
  }
  REP(i, n) printf("%s%c", ans[i].c_str(), " \n"[i == n - 1]);
  return 0;
}