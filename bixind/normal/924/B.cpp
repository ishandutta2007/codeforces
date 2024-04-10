#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 998244353;

void solve() {
  ld ans = 0;
  int n, U;
  cin >> n >> U;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int k = 0;
  for (int i = 0; i < n; ++i) {
    while (k < n && v[i] + U >= v[k])
      ++k;
    if (i + 2 < k) {
      ans = max(ans, ((ld) (v[k - 1] - v[i + 1])) / (v[k - 1] - v[i]));
    }
  }
  if (ans == 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();

  return 0;
}