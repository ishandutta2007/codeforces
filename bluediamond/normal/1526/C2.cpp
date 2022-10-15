#include <bits/stdc++.h>

using namespace std;

#define int long long
multiset<int> taken;
int sum;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int foo;
    cin >> foo;
    taken.insert(foo);
    sum += foo;
    while (sum < 0) {
      sum -= *taken.begin();
      taken.erase(taken.begin());
    }
  }
  cout << (int) taken.size() << "\n";

  return 0;
}