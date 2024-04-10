#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  int ans = 0, cur = 0;
  while (d--) {
    string s;
    cin >> s;
    if (strchr(s.c_str(), '0')) {
      ans = max(ans, ++cur);
    } else {
      cur = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}