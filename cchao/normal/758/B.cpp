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
  map<int, char> m;
  REP(i, SZ(s)) {
    if (s[i] != '!') {
      m[i % 4] = s[i];
    }
  }
  map<char, int> cnt;
  REP(i, SZ(s)) {
    if (s[i] == '!') {
      cnt[m[i % 4]]++;
    }
  }
  printf("%d %d %d %d\n", cnt['R'], cnt['B'], cnt['Y'], cnt['G']);
  return 0;
}