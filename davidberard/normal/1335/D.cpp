#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char oth(char x) {
  if (x >= '1' && x <= '8') return x+1;
  if (x == '9') return '1';
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    string s[9];
    for (int i=0; i<9; ++i) {
      cin >> s[i];
    }
    for (int i=0; i<9; ++i) {
      int j = (i%3)*3 + (i/3);
      s[i][j] = oth(s[i][j]);
    }
    for (int i=0; i<9; ++i) {
      cout << s[i] << "\n";
    }
  }
  return 0;
}