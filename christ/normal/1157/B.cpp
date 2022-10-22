#include <bits/stdc++.h>
using namespace std;
int f[10];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  string s, res;
  cin >> n;
  cin >> s;
  for (int x = 1; x < 10; x++) cin >> f[x];
  int first = -1;
  bool found = 0, done = 0;
  for (int x = 0; x < s.length(); x++) {
    if (!found && f[s[x]-'0'] > s[x]-'0') {
      found = 1;
      res += (char)(f[s[x]-'0']+'0');
    }
    else if (!found || done) res += s[x];
    else if (f[s[x]-'0'] >= s[x]-'0') {
      res += (char)(f[s[x]-'0']+'0');
    }
    else {
      done = 1;
      res += s[x];
    }
  }
  cout << res << '\n';
}