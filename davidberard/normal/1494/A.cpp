#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char v[256];
string s;

bool solve() {
  int r = 0;
  for (int i=0; i<s.size(); ++i) {
    r += (v[(int) s[i]] == '(' ? 1 : -1);
    if (r < 0) {
      return false;
    }
  }
  return r == 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> s;
    bool ans = false;
    for (int i=0; i<7; ++i) {
      for (int r=0; r<3; ++r) {
        v[r+'A'] = (!!(i&(1<<r)) ? '(' : ')');
      }
      ans |= solve();
    }
    cout << (ans ? "YES" : "NO") << "\n";
  }
  return 0;
}