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
  int n;
  cin >> n;
  int x = 0;
  REPE(i, 1, n) {
    int d;
    string s;
    cin >> d >> s;
    if (x == 0 && s[0] != 'S') {
      puts("NO");
      return 0;
    }
    if (x == 20000 && s[0] != 'N') {
      puts("NO");
      return 0;
    }
    if (s[0] == 'S') {
      x += d;
    } else if(s[0] == 'N') {
      x -= d;
    }
    if (x < 0 || x > 20000) {
      puts("NO");
      return 0;
    }
  }
  if (x != 0) {
    puts("NO");
  } else puts("YES");
  return 0;
}