#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;

inline int idx(char c) {
  if (c == 'L') return 0;
  else if (c == 'R') return 1;
  else if (c == 'U') return 2;
  else return 3;
}

int n;
string s;

int main() {
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    int v[4] = {};
    while (j < n && !v[idx(s[j]) ^ 1]) {
      v[idx(s[j])] = true;
      j++;
    }
    ans++;
    i = j;
  }
  cout << ans << endl;
  return 0;
}