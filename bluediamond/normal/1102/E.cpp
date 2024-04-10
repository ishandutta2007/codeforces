#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int n;
  cin >> n;
  map<int, int> last;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {cin >> v[i]; last[v[i]] = i;}
  int i = 0, ret = 1;
  while (i < n) {
    int j = last[v[i]];
    while (i <= j) {
      j = max(j, last[v[i]]);
      i++;
    }
    if (i < n) {
      ret = 2 * ret % M;
    }
  }
  cout << ret << "\n";
}