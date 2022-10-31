#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
string s;
int cnt[128];
int main() {
  REP(i, 128) {
    if (i == 'A' || i == 'G' || i == 'C' || i == 'T') {
    } else {
      cnt[i] = 1e9;
    }
  }
  cin >> s;
  cin >> s;
  for (char c : s) cnt[c]++;
  for (char &c : s) if (c == '?') {
    int p = min_element(cnt, cnt + 128) - cnt;
    c = p;
    cnt[p]++;
  }
  if (cnt['A'] != cnt['G'] || cnt['A'] != cnt['C'] || cnt['A'] != cnt['T']) {
    puts("===");
  } else cout << s << endl;
  return 0;
}