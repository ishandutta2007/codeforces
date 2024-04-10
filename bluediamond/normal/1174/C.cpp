#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int a[123456];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, tzuc = 0;
  vector<int> p;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    bool good = 1;
    for (auto &x : p) {
      if (x * x > i) break;
      if (i % x == 0) {
        good = 0; break;
      }
    }
    p.push_back(i);
    for (int j = i + !good * (int) 1e8; j <= n; j += i) j[a] = tzuc += (j == i);
  }
  for (int i = 2; i <= n; i++) cout << a[i] << " ";
  cout << "\n";


}