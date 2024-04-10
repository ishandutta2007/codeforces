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

string read() {
  static char s[300010];
  int c[26] = {};
  scanf("%s", s);
  for (int i = 0; s[i]; ++i)
    c[s[i] - 'a']++;
  string ret = "";
  REP(i, 26) REP(j, c[i]) ret += char('a' + i);
  return ret;
}

char s[300010];
int l, r;
int main() {
  string a = read();
  string b = read();
  reverse(ALL(b));
  int n = SZ(a);
  l = 0, r = n - 1;
  int i = 0, j = 0;
  int ii = 0, jj = 0;
  jj = n / 2 - 1;
  ii = n - n / 2 - 1;
  int turn = 0;
  while (l <= r) {
    if (turn == 0) {
      if (b[j] > a[i]) s[l++] = a[i++];
      else s[r--] = a[ii--];
    } else {
      if (a[i] < b[j]) s[l++] = b[j++];
      else s[r--] = b[jj--];
    }
    turn ^= 1;
  }
  puts(s);
  return 0;
}