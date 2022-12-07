#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int64_t n,m;
  cin >> n >> m;
  int64_t ans = 0;
  if (m != 1) {
    ans += n*(m-1);
  } else {
    ans += n-1;
  }
  cout << ans << '\n';
}