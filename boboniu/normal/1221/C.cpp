#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >>c;
    int ans = (a + b + c) / 3;
    ans = min(ans, min(a, b));
    printf("%d\n", ans);
  }
}