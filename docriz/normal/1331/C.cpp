#include <bits/stdc++.h>

using namespace std;

int main() {
  int x;
  cin >> x;
  string s;
  for (int i = 0; i < 6; i++) {
    s += (char)(x % 2 + '0');
    x >>= 1;
  }
  swap(s[0], s[4]);
  swap(s[2], s[3]);
  reverse(s.begin(), s.end());
  int ans = 0;
  for (int i = 0; i < 6; i++) {
    ans = ans * 2 + s[i] - '0';
  }
  cout << ans << endl;
  return 0;
}