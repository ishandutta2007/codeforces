#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int now = n;
  long long ans = 0;
  while(now > 1 && k > 0) {
    ans += (now-1)*2 - 1;
    now -= 2;
    k--;
  }
  cout << ans << endl;
  return 0;
}