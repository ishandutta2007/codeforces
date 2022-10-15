#include <bits/stdc++.h>

using namespace std;

int n, p, ans;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      p++;
      ans += (p == 0);
    } else {
      p--;
    }
    ans += (p < 0);
  }
  if (p != 0) {
    ans = -1;
  }
  cout << ans << "\n";
}