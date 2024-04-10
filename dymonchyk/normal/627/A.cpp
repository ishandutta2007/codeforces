#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  long long s, x;
  cin >> s >> x;
  vector<long long> v;
  long long ans = 1;
  for (int i = 0; i < 60; ++i) {
    if (x & (1LL<<i)) {
      s -= 1LL << i;
      ans <<= 1;
    } else
      v.push_back(1LL << (i + 1));
  }
  bool has = false;
  for (int i = (int) v.size() - 1; i >= 0; --i) {
    if (s >= v[i]) {
      s -= v[i];
      has = true;
    }
  }
  if (!has) ans -= 2;
  if (s != 0) ans = 0;
  cout << ans << endl;
  return 0;
}