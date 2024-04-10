#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  long long ans = 0;
  for (int r = 1; r < b; ++r) {
    int cnt = a;
    ans += 1LL * cnt * r % mod + 1LL * b * (1LL * cnt * (cnt + 1) / 2 % mod * r % mod) % mod;
  }
  cout << ans % mod << endl;
  return 0;
}