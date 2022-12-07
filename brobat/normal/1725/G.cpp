#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int64_t n;
  cin >> n;
  if (n == 1) {
    cout << 3 << '\n';
    return 0;
  }
  n-=2;
  int64_t stage = n/3;
  int64_t st = 5 + 4*stage;
  int64_t t = n%3;
  int64_t ans = st;
  if (t == 0) {
    ans = st;
  } else if (t == 1) {
    ans = st+2;
  } else {
    ans = st+3;
  }
  cout << ans << '\n';
}