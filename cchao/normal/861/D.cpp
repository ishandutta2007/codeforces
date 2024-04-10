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

using ULL = unsigned long long;
ULL rnd() {
  LL r = rand();
  r <<= 30;
  r ^= rand();
  r <<= 30;
  r ^= rand();
  return r;
}

int n;
char s[100010][12];

ULL id[100010];

map<int, ULL> h[10];

int main() {
  srand(time(NULL));
  scanf("%d", &n);
  REP(x, n) {
    id[x] = rnd();
    scanf("%s", s[x]);
    set<int> f[10];
    REP(i, 9) {
      int r = 0;
      for (int j = i; j < 9; ++j) {
        r = r * 10 + (s[x][j] - '0');
        if (f[j-i].count(r) == 0) {
          h[j - i][r] ^= id[x];
          f[j-i].insert(r);
        }
      }
    }
  }
  REP(x, n) {
    string ans = string(s[x]);
    REP(i, 9) {
      int r = 0;
      string t = "";
      for (int j = i; j < 9; ++j) {
        r = r * 10 + (s[x][j] - '0');
        t += s[x][j];
        if (h[j - i][r] == id[x] && t.size() < ans.size())
          ans = t;
      }
    }
    puts(ans.c_str());
  }
  return 0;
}